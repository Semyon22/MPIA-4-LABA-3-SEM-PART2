#define CATCH_CONFIG_RUNNER
#include "activity.h"
#include "activities.h"
#include "catch.hpp"
#include <chrono>
#include <random>
#include <numeric>
using namespace std;

vector<Activity> random_data(int size)
{
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, size / 2);
	vector <Activity> result;
	while (result.size() < size)
	{
		int s = distribution(generator);
		int f = distribution(generator);
		if (s < f) {
			result.push_back(Activity(s, f));
		}
	}
	return result;
}

double get_max_activities_time(const vector<Activity>& activities)
{
	auto t1 = std::chrono::high_resolution_clock::now();
	auto result = get_max_activities(activities);
	auto t2 = std::chrono::high_resolution_clock::now();
	double time = std::chrono::duration<double>(t2 - t1).count();
	return time;
}

double full_enumeration_time(const vector<Activity>& activities)
{
	auto t1 = std::chrono::high_resolution_clock::now();
	auto result = full_enumeration(activities);
	auto t2 = std::chrono::high_resolution_clock::now();
	double time = std::chrono::duration<double>(t2 - t1).count();
	return time;
}

void time(int size)
{
	vector<Activity> data = random_data(size);
	cout << full_enumeration_time(data) << endl;
	cout << get_max_activities_time(data) << endl;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	time(10000000*4);
	int result4 = Catch::Session().run(argc, argv);
	return result4;
}