
#include <string>
#include <iostream>


#include "Date.h"
#include "Time.h"
#include "Utility.h"

vector<int> Tribonacci{1, 3, 5, 9, 17, 31, 55, 81, 149, 274, 504, 927};

class Patient {
public:
    int age;
    int appointment;
    int score;
    int count_late;
    int time_consulting;

    Time response_time;
    Time time_arrival;
    Time expected_time;

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

        this->score = min(this->score, 20);
        this->count_late += 1;
    }

    Patient() : time_arrival(Time(0, 0, 0)),
                expected_time(Time(0, 0, 0)),
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

    void fillRandom() {
        auto _expected_time = Time(getRandomNumber(10, 14), getRandomNumber(0, 59),
                                   0);

        auto _arrival_time = Time(getRandomNumber(_expected_time.getHours(), 14),
                                  getRandomNumber(0, 59), 0);

        this->appointment = ++Patient::count_patients;
        this->age = getRandomNumber(20, 75);
        this->expected_time = _expected_time;
        this->time_arrival = _arrival_time;

        this->score = this->appointment;
        if (40 <= this->age && this->age <= 65) {
            this->score += 2;
        } else {
            this->score += 4;
        }

        this->time_consulting = getRandomNumber(3, 10);
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
         << "treated?: " << patient.treated << ' ';

    return COUT;
}

int Patient::count_patients = 0;

