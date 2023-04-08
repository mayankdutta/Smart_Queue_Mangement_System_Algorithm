#include <iostream>
#include <vector>
#include "bits/stdc++.h"
#include "Patient.h"

using namespace std;
using namespace std::chrono;

bool comparator(const Patient &patient1, const Patient &patient2) {
    if (patient1.score == patient2.score) {
        return patient1.appointment < patient2.appointment;
    }
    return patient1.score < patient2.score;
}

void re_order(vector<Patient> &patients) {
    sort(patients.begin(), patients.end(), comparator);
}

int main() {
    vector<Patient> patients(25);


    for (int i = 0; i < patients.size(); i++) {
        patients[i].fillRandom(i, patients.size());
    }

    Time start_time = Time(10, 0, 0);
    Time end_time = Time(14, 0, 0);

    re_order(patients);

    Time time_stacked;
    int temp_count = 0;
    int temp_threshold = 200;

    for (Time i = start_time; i <= end_time; i = i + 60) {
//        cout << "current time: " << i << '\n';
        for (int current_patient = 0; current_patient < patients.size(); ) {
//            cout << patients[current_patient].appointment << ' ' << patients[current_patient].time_arrival << ' '  << patients[current_patient].score << '\n';

            if (patients[current_patient].time_arrival <= i) {
//                cout << "present\n";

                patients[current_patient].set_time(time_stacked);
                current_patient++;
                time_stacked = time_stacked + patients[current_patient].time_consulting;

            } else {
                if (temp_count > temp_threshold) break;
//                cout << "absent\n";

                patients[current_patient].change_score();
                re_order(patients);

                temp_count ++;
            }
        }
    }

    for (const auto &patient: patients) {
        cout << patient << '\n';
    }
}
