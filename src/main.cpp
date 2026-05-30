// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"
#include "vector"
#include "cstdlib"
#include "ctime"

int main() {
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  const int MAX_LENGTH = 60;
  std::vector<int> lengths;
  std::vector<int> lightsOff;
  std::vector<int> lightsOn;
  std::vector<int> lightsChaotic;

  for (int i = 2; i <= MAX_LENGTH; ++i) {
    Train trainLightsOff;
    for (int j = 0; j < i; ++j) {
      trainLightsOff.addCar(false);
    }
    trainLightsOff.getLength();
    lightsOff.push_back(trainLightsOff.getOpCount());

    Train trainLightsOn;
    for (int j = 0; j < i; ++j) {
      trainLightsOn.addCar(true);
    }
    trainLightsOn.getLength();
    lightsOn.push_back(trainLightsOn.getOpCount());

    Train trainLightsChaotic;
    for (int j = 0; j < i; ++j) {
      trainLightsChaotic.addCar(std::rand() % 2 == 0);
    }
    trainLightsChaotic.getLength();
    lightsChaotic.push_back(trainLightsChaotic.getOpCount());

    lengths.push_back(i);
  }
  std::cout << "i, lights off, lights on, chaotic lights\n";
  for (size_t i = 0; i < lengths.size(); ++i) {
    std::cout << lengths[i] << ','
      << lightsOff[i] << ','
      << lightsOn[i] << ','
      << lightsChaotic[i] << '\n';
  }
  return 0;
}
