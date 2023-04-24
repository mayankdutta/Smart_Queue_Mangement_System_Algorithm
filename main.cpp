// TODO: make two vector, one for treated, one for remaining.

#include <iostream>
#include <vector>
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

bool comparator2(const Patient &patient1, const Patient &patient2) {
    if (patient1.time_arrival == patient2.time_arrival) {
        return patient1.appointment < patient2.appointment;
    }
    return patient1.time_arrival <= patient2.time_arrival;
}

int main() {
    vector<Patient> patients(500);

    for (int i = 0; i < patients.size(); i++) {
        patients[i].fillRandom(i, (int) patients.size());
    }

    Time start_time = Time(10, 0, 0);
    Time end_time = Time(14, 0, 0);

    re_order(patients);

    Time time_stacked;
    int temp_count = 0;
    int temp_threshold = 20;

//    int current_patient = 0;
    for (Time i = start_time; i <= end_time + 60; i = i + 60) {
//        cout << "current_time : " << i << '\n';

        time_stacked = Time(0, 0, 0);
        for (int current_patient = 0; current_patient < patients.size();) {

//            cout << current_patient << ' ' << time_stacked << '\n';
            if (current_patient < patients.size() && patients[current_patient].treated) {
//                cout << "In while loop\n";

                current_patient++;
                continue;
            }

            if (patients[current_patient].time_arrival <= i) {
//                cout << "patient: " << current_patient << ", present\n";
                patients[current_patient].set_time(time_stacked);

//                auto arrival_time = patients[current_patient].time_arrival;
//                int arrival_time_seconds = arrival_time.getHours() * 60 * 60 + arrival_time.getMinutes() * 60;
//
//                Time ans = i - arrival_time_seconds;
//                cout << "current, patient:  " << current_patient << ' ' << i << ' ' << arrival_time << '\n';
//                patients[current_patient].set_time(ans);

                time_stacked = time_stacked + patients[current_patient].time_consulting;
                current_patient++;

            } else {

                if (patients[current_patient].score >= 2000) {
                    current_patient++;
//                    cout << "current patient: " << current_patient << " , & current score is : " << patients[current_patient].score << '\n';
//                    cout << "score exceeding 2000\n";
                } else {
//                    cout << "reordering \n";
//                    cout << "current patient: " << current_patient << " , & current score is : " << patients[current_patient].score << '\n';

                    patients[current_patient].change_score();
                    re_order(patients);
//                    temp_count++;
                }
            }
        }

//        cout << "End of one cycle\n";

        for (auto &patient: patients) {
            if ((!patient.treated) && patient.score >= 2000) {
                patient.score = 20;
                patient.count_late = 2;
            }
        }

    }

//    for (const auto &patient: patients) {
//        cout << patient << '\n';
//    }

    sort(patients.begin(), patients.end(), comparator2);

    cout << "\n\n ******************************************** \n\n";



    for (int i = 1; i < patients.size(); i++) {
        int i_time_arrival = patients[i].time_arrival.getHours() * 60 * 60 + patients[i].time_arrival.getMinutes() * 60 + patients[i].time_arrival.getSeconds();
        patients[i].response_time = max(
                Time(0, 0, 0),
                patients[i - 1].time_arrival + patients[i - 1].time_consulting - i_time_arrival);
    }

    for (const auto &patient: patients) {
        cout << patient << '\n';
    }
}
