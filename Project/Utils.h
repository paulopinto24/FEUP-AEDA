#pragma once

#include "UghEatsFD.h"
#include <iostream>
#include <fstream>
using namespace std;

int loadApplication(UghEatsFD *p1);

int saveApplication(UghEatsFD *p1);

vector<string> parseBySemiColon(string line);

vector<string> parseBySlash(string line);

Base parseBase(vector<string> vec);


