#include "activities.h"

vector<Activity> get_max_activities(const vector<Activity>& activities_c)
{
    vector<Activity> result;
    if (activities_c.size() == 0) {
        return result;
    }
    vector<Activity> activities(activities_c.begin(), activities_c.end());
    sort(activities.begin(), activities.end(), [](const Activity& a1, const Activity& a2) {return a1.finish < a2.finish; });

    result.push_back(activities[0]);

    for (int i = 0; i < activities.size(); ++i)
    {
        if (result[result.size() - 1].finish <= activities[i].start) {
            result.push_back(activities[i]);
        }
    }

    return result;
}

vector<Activity> full_enumeration(const vector<Activity>& activities)
{
    vector <Activity> result;
    if (activities.empty()) {
        return result;
    }

    Activity a = activities[0];
    for (auto i = 0; i < activities.size(); ++i)
    {
        if (activities[i].finish < a.finish) {
            a = activities[i];
        }
    }
    result.push_back(a);

    for (auto i = 0; i < activities.size(); ++i)
    {
        Activity b = activities[i];
        if (a.finish <= b.start)
        {
            for (auto j = 0; j < activities.size(); ++j)
            {
                if (activities[j].finish > a.finish and activities[j].finish < b.finish and a.finish <= activities[j].start)
                {
                    bool k = false;
                    for (auto it = 0; it < result.size(); ++it)
                    {
                        if (activities[j] == result[it])
                        {
                            k = true;
                            break;
                        }
                    }
                    if (!k) {
                        b = activities[j];
                    }
                }
            }
            result.push_back(b);
            a = b;
        }
    }


    return result;
}