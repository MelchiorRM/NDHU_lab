#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

// Class to represent a support topic
class Topic {
public:
    int id;
    int numRequests;
    int firstRequestTime;
    int serviceTime;
    int interval;

    Topic() : id(0), numRequests(0), firstRequestTime(0), serviceTime(0), interval(0) {}
    
    void readInput() {
        cin >> id >> numRequests >> firstRequestTime >> serviceTime >> interval;
    }
};

// Class to represent a job (individual request)
class Job {
public:
    int topicId;
    int startTime;
    int processingTime;

    Job(int tid = 0, int st = 0, int pt = 0) : topicId(tid), startTime(st), processingTime(pt) {}
};

// Custom comparator for Job priority queue
struct JobComparator {
    bool operator()(const Job& a, const Job& b) const {
        return a.startTime > b.startTime; // Min-heap based on start time
    }
};

// Class to represent a staff member
class Staff {
public:
    int id;
    vector<int> topicPriorities;
    bool isWorking;
    int lastJobTime;
    int finishTime;

    Staff() : id(0), isWorking(false), lastJobTime(0), finishTime(0) {}

    void readInput() {
        int numTopics;
        cin >> id >> numTopics;
        topicPriorities.resize(numTopics);
        for (int i = 0; i < numTopics; ++i) {
            cin >> topicPriorities[i];
        }
    }
};

// Class to manage the scheduling process
class Scheduler {
private:
    vector<Topic> topics;
    vector<Staff> staff;
    map<int, priority_queue<Job, vector<Job>, JobComparator>> jobQueue;
    priority_queue<int, vector<int>, greater<int>> timeline;
    int currentTime;
    int maxTime;

public:
    Scheduler() : currentTime(-1), maxTime(-2) {}

    void readScenario() {
        int numTopics;
        cin >> numTopics;
        if (numTopics == 0) return;

        // Read topics
        topics.resize(numTopics);
        for (int i = 0; i < numTopics; ++i) {
            topics[i].readInput();
            generateJobs(topics[i]);
        }

        // Read staff
        int numStaff;
        cin >> numStaff;
        staff.resize(numStaff);
        for (int i = 0; i < numStaff; ++i) {
            staff[i].readInput();
        }

        // Sort staff by ID for consistent processing
        sort(staff.begin(), staff.end(), [](const Staff& a, const Staff& b) {
            return a.id < b.id;
        });
    }

    void generateJobs(const Topic& topic) {
        int currentTime = topic.firstRequestTime;
        for (int i = 0; i < topic.numRequests; ++i) {
            jobQueue[topic.id].push(Job(topic.id, currentTime, topic.serviceTime));
            timeline.push(currentTime);
            currentTime += topic.interval;
        }
    }

    void processScenario(int scenarioNum) {
        if (topics.empty()) return;

        timeline.push(-1); // Placeholder for initial time
        while (!timeline.empty()) {
            int nextTime = timeline.top();
            timeline.pop();
            if (nextTime == maxTime) continue;
            currentTime = maxTime = nextTime;

            // Update staff availability
            for (Staff& s : staff) {
                if (s.isWorking && s.finishTime <= currentTime) {
                    s.isWorking = false;
                }
            }

            // Find available staff, sorted by last job time
            vector<pair<int, int>> availableStaff; // {lastJobTime, index}
            for (int i = 0; i < staff.size(); ++i) {
                if (!staff[i].isWorking) {
                    availableStaff.emplace_back(staff[i].lastJobTime, i);
                }
            }
            sort(availableStaff.begin(), availableStaff.end());

            // Assign jobs to available staff
            for (const auto& [_, idx] : availableStaff) {
                Staff& s = staff[idx];
                for (int tid : s.topicPriorities) {
                    if (!jobQueue[tid].empty()) {
                        Job job = jobQueue[tid].top();
                        if (job.startTime <= currentTime) {
                            jobQueue[tid].pop();
                            s.isWorking = true;
                            s.lastJobTime = currentTime;
                            s.finishTime = currentTime + job.processingTime;
                            timeline.push(s.finishTime);
                            break;
                        }
                    }
                }
            }
        }

        cout << "Scenario " << scenarioNum << ": All requests are serviced within " 
             << maxTime << " minutes." << endl;
    }

    bool isEmpty() const {
        return topics.empty();
    }
};

int main() {
    int scenarioNum = 0;
    while (true) {
        Scheduler scheduler;
        scheduler.readScenario();
        if (scheduler.isEmpty()) break;
        scheduler.processScenario(++scenarioNum);
    }
    return 0;
}