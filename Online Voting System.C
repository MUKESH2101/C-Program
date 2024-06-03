#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

struct Candidate {
    char name[50];
    int votes;
};

struct Candidate candidates[MAX_CANDIDATES];
int numCandidates = 0;

struct Voter {
    char name[50];
    int voted;
};

struct Voter voters[MAX_VOTERS];
int numVoters = 0;

void addCandidate(const char *name) {
    if (numCandidates < MAX_CANDIDATES) {
        strcpy(candidates[numCandidates].name, name);
        candidates[numCandidates].votes = 0;
        numCandidates++;
        printf("Candidate added successfully!\n");
    } else {
        printf("Maximum number of candidates reached!\n");
    }
}

void displayCandidates() {
    printf("Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void vote(int candidateIndex) {
    if (candidateIndex >= 0 && candidateIndex < numCandidates) {
        candidates[candidateIndex].votes++;
        printf("Vote casted successfully!\n");
    } else {
        printf("Invalid candidate index!\n");
    }
}

int main() {
    int choice;
    char name[50];
    int candidateIndex;

    do {
        printf("\nOnline Voting System Menu:\n");
        printf("1. Add Candidate\n");
        printf("2. Display Candidates\n");
        printf("3. Cast Vote\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                addCandidate(name);
                break;
            case 2:
                displayCandidates();
                break;
            case 3:
                printf("Enter the index of the candidate you want to vote for: ");
                scanf("%d", &candidateIndex);
                vote(candidateIndex - 1); // Adjust index to match array index
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
