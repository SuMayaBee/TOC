#include <iostream>
using namespace std;

int main() {
    int num_of_stage, num_of_input, present_state, final_state, input[10], len = 0;
    cout << "Enter stage number & number of input ";
    cin >> num_of_stage >> num_of_input;
    char stage[num_of_stage];
    for (int i = 0; i < num_of_stage; i++) {
        cout << "Enter stages: ";
        cin >> stage[i];
    }
    int input_alpha[num_of_input];
    for (int j = 0; j < num_of_input; j++) {
        cout << "Enter input alphabet ";
        cin >> input_alpha[j];
    }

    cout << "Enter input string (-1 to stop): ";
    for (int i = 0; i < 10; i++) {
        cin >> input[i];
        len++;
        if (input[i] == -1)
            break;
    }
    char p_state, f_state;
    cout << "Enter present & final state: ";
    cin >> p_state >> f_state;

    int present_state_index = -1;
    int final_state_index = -1;

    // Find the indices of present and final states in the stage array
    for (int i = 0; i < num_of_stage; i++) {
        if (p_state == stage[i])
            present_state_index = i;
        if (f_state == stage[i])
            final_state_index = i;
    }

    if (present_state_index == -1 || final_state_index == -1) {
        cout << "Invalid present or final state." << endl;
        return 1;
    }

    // Initialize transition matrix
    int arr[2][100][100];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < num_of_stage; j++) {
            cout << "For input " << i << " stage " << stage[j] << " goes to num of stages: ";
            int stage_goes;
            cin >> stage_goes;
            for (int k = 0; k < stage_goes; k++) {
                cout << "\nStage: ";
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 0)
                    arr[i][j][k] = -1;
            }
        }
    }

    // NFA simulation
    int current_state = present_state_index;
    for (int x = 0; x < len - 1; x++) {
        int check = input[x];
        int next_state = -1;

        // Find the next state based on current state and input
        for (int i = 0; i < num_of_stage; i++) {
            if (arr[check][current_state][i] != -1) {
                next_state = arr[check][current_state][i];
                break;
            }
        }
        if (next_state == -1) {
            cout << "No transition found for input " << input_alpha[check] << " in state " << stage[current_state] << endl;
            cout << "Rejected" << endl;
        }

        current_state = next_state;
        cout << "Updated state: " << stage[current_state] << endl;

        if (current_state == final_state_index) {
            cout << "Accepted" << endl;
            break;
        }
    }
    if (current_state != final_state_index) {
        cout << "Rejected" << endl;
    }

    return 0;
}