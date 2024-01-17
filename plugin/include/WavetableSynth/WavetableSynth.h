#pragma once
#include <juce_audio_processors/juce_audio_processors.h>

#include <vector>

#include "WavetableOscillator.h"

namespace audio_plugin
{

class WavetableSynth
{
public:
  void prepareToPlay(double sampRate);
  void processBlock(juce::AudioBuffer<float> &buffer, juce::MidiBuffer &);

private:
  void initializeOscillators();
  std::vector<float> generateSineWaveTable();
  void handleMidiEvent(const juce::MidiMessage &midiEvent);
  float midiNoteNumberToFrequency(int midiNoteNumber);
  void render(juce::AudioBuffer<float> &buffer, int startSample, int endSample);

  double sampleRate;
  std::vector<WavetableOscillator> oscillators;
};
}  // namespace audio_plugin