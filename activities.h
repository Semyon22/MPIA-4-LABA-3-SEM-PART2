#pragma once
#include "activity.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<Activity> get_max_activities(const vector<Activity>& activities);
vector<Activity> full_enumeration(const vector<Activity>& activities);
