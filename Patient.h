
#include <string>
#include <iostream>


#include "Date.h"
#include "Time.h"
#include "Utility.h"

vector<int> Tribonacci{1, 3, 5, 9, 17, 31, 55, 81, 149, 274, 504, 927, 1705, 3136, 5768};

class Patient {
public:
    int age;
    int appointment;
    int score;
    int count_late;
    int time_consulting;

    Time response_time;
    Time time_arrival;
    pair<Time, Time> expected_time;

    static int count_patients;

    bool treated;

    void set_time(Time &stacked_time) {
        this->response_time = stacked_time;
        this->treated = true;
    }

    void change_score() {
        if (count_late < Tribonacci.size()) {
            this->score += Tribonacci[this->count_late];
        }

        this->score = min(this->score, 2000);
        this->count_late += 1;
    }

    Patient() : time_arrival(Time(0, 0, 0)),
                expected_time({Time(0, 0, 0), Time(0, 0, 0)}),
                response_time(Time(0, 0, 0)) {

        this->age = 0;
        this->appointment = 0;
        this->score = 0;
        this->count_late = 0;
        this->time_consulting = 0;
        this->treated = false;
    }

    Patient(const Patient &patient)
            : time_arrival(patient.time_arrival),
              expected_time(patient.expected_time),
              response_time(patient.response_time) {

        this->age = patient.age;
        this->appointment = patient.appointment;
        this->score = patient.score;
        this->count_late = patient.count_late;
        this->time_consulting = patient.time_consulting;
        this->response_time = patient.response_time;
        this->treated = patient.treated;
    }

    void fillRandom(int i, int total_size) {

        pair<Time, Time> _expected_time;

        if (i < total_size / 4) {
            _expected_time = {Time(10, 0, 0), Time(11, 0, 0)};
        } else if (total_size / 4 <= i && i < 2 * total_size / 4) {
            _expected_time = {Time(11, 0, 0), Time(12, 0, 0)};
        } else if (2 * total_size / 4 <= i && i < 3 * total_size / 4) {
            _expected_time = {Time(12, 0, 0), Time(13, 0, 0)};
        } else if (3 * total_size / 4 <= i && i < 4 * total_size / 4) {
            _expected_time = {Time(13, 0, 0), Time(14, 0, 0)};
        }

        auto _arrival_time = Time(getRandomNumber(_expected_time.first.getHours(), 13),
                                  getRandomNumber(0, 59), 0);

        this->appointment = ++Patient::count_patients;
        this->age = getRandomNumber(20, 75);
        this->expected_time.first = _expected_time.first;
        this->expected_time.second = _expected_time.second;
        this->time_arrival = _arrival_time;

        this->score = this->appointment;
        if (40 <= this->age && this->age <= 65) {
            this->score += 2;
        } else {
            this->score += 4;
        }

        this->time_consulting = getRandomNumber(3 * 60, 25 * 60);
    }

    Patient &operator=(const Patient &patient) = default;
};

std::ostream &operator<<(std::ostream &COUT, const Patient &patient) {
    COUT << "initial order: " << patient.appointment << ' '
         << "score: " << patient.score << ' '
         << "count late : " << patient.count_late << ' '
         << "response time: " << patient.response_time << ' '
         << "time of arrival: " << patient.time_arrival << ' '
         << "expected time: " << patient.expected_time << ' '
         << "treated: " << patient.treated << ' '
         << "consult time: " << patient.time_consulting / 60 << "m " << patient.time_consulting % 60 << "s " << ' ';

    return COUT;
}

int Patient::count_patients = 0;

