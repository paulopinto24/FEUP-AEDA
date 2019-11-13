#pragma once

#include "UghEatsFD.h"
#include <fstream>

using namespace std;

int loadApplication(UghEatsFD *p1);

int saveApplication(UghEatsFD *p1);

vector<string> parseBySemiColon(string line);

Base parseBase(vector<string> vec);


