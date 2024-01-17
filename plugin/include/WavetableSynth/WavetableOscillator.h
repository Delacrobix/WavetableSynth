#pragma once
#include <vector>

namespace audio_plugin
{

class WavetableOscillator
{
public:
  WavetableOscillator(std::vector<float> waveTable, double sampleRate);

  void setFrequency(float frequency);
  float getSample();
  float interpolateLinearly();

  void stop();
  bool isPlaying();

private:
  std::vector<float> waveTable;
  double sampleRate;
  float index = 0.f;
  float indexIncrement = 0.f;
};
}