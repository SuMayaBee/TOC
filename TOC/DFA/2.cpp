#include <stdio.h>
#include <string.h>

// Define a structure to store the NFA
typedef struct NFA {
    int delta[10][2][10];  // Transition function, delta[q][a][p] is a transition from q with symbol a to p
    int no_of_transitions[10][2];  // Number of transitions for each state on each symbol (0 or 1)
    int nos;  // Number of states
    int start_state;  // Start state
    int final_states[10];  // List of final states
    int nof;  // Number of final states
} NFA;

int main() {
    NFA nfa;

    // Read number of states, start state, and final states
    printf("Enter the number of states: ");
    scanf("%d", &nfa.nos);
    printf("Enter the start state: ");
    scanf("%d", &nfa.start_state);
    printf("Enter the number of final states: ");
    scanf("%d", &nfa.nof);
    for (int i = 0; i < nfa.nof; i++) {
        printf("Enter final state no %d: ", i + 1);
        scanf("%d", &nfa.final_states[i]);
    }

    // Read transitions
    for(int i = 0; i < nfa.nos; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Enter number of transitions for state q%d on input %d: ", i, j);
            scanf("%d", &nfa.no_of_transitions[i][j]);
            for(int k = 0; k < nfa.no_of_transitions[i][j]; k++) {
                printf("Enter next state for transition %d: ", k + 1);
                scanf("%d", &nfa.delta[i][j][k]);
            }
        }
    }

    // Read input string
    char input_string[100];
    printf("Enter the input string (only 0's and 1's): ");
    scanf("%s", input_string);

    // Initialize current states
    int states[10] = {0};
    states[nfa.start_state] = 1;  // Start state is active
    int newStates[10];  // Next states
    char path[1000] = "";  // Path string

    // Simulate NFA
    for(int i = 0; i < strlen(input_string); i++) {
        int sym = input_string[i] - '0';  // Convert '0' or '1' to integer
        if(sym < 0 || sym > 1) {  // Invalid input
            printf("Rejected\n");
            return 0;
        }

        // Initialize next states
        memset(newStates, 0, sizeof(newStates));
        
        // Process transitions
        for(int j = 0; j < nfa.nos; j++) {
            if(states[j]) {  // If state j is active
                for(int k = 0; k < nfa.no_of_transitions[j][sym]; k++) {
                    int next = nfa.delta[j][sym][k];
                    newStates[next] = 1;  // Activate next state
                    
                    // Update path
                    char transition[50];
                    sprintf(transition, "q%d -(%d)-> q%d\n", j, sym, next);
                    strcat(path, transition);
                }
            }
        }

        // Update current states
        memcpy(states, newStates, sizeof(newStates));
    }

    // Check for acceptance
    int accepted = 0;
    for(int i = 0; i < nfa.nof; i++) {
        if(states[nfa.final_states[i]]) {
            accepted = 1;
            break;
        }
    }

    // Print result
    if(accepted) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    // Print transition path
    printf("Path of transition:\n%s", path);

    return 0;
}
