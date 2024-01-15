#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <numeric>

using namespace std;

void recursiveSentence(long int arr[], int data[], int start, int end, int index, long int sentence_size, long int &num_valid_sentences) {

    long int curr_sentence_value = 0;
    
    // Current sentence is ready to be checked
    if (index == sentence_size) {
        curr_sentence_value = 0;
        for (int i = 0; i < sentence_size; i++) {
            curr_sentence_value = curr_sentence_value | data[i];
        }
        if (curr_sentence_value == 67108863) {
            num_valid_sentences++;
        }
    }

    // Recursively creating new valid combo
    for (int i = start; i <= end && end - i + 1 >= sentence_size - index; i++) {
        data[index] = arr[i];
        recursiveSentence(arr, data, i+1, end, index+1, sentence_size, num_valid_sentences);
    }
}

void generateNumValidSentences(long int arr[], int array_size, long int sentence_size, long int &num_valid_sentences) {
    int data[sentence_size];
    recursiveSentence(arr, data, 0, array_size-1, 0, sentence_size, num_valid_sentences);
    return;
}

int main() {

    // initializing variables
    int num_words;
    string curr_word;
    long int curr_num_rep;
    int index = 0;
    int temp;

    // taking input
    cin >> num_words;
    long int words[num_words];
    while (num_words > 0) {
        cin >> curr_word;
        curr_num_rep = 0;
        for (int i = 0; i < curr_word.length(); i++) {
            temp = pow(2, int(curr_word[i] - 97));
            curr_num_rep = curr_num_rep | temp;
        }
        words[index] = curr_num_rep;
        num_words--;
        index++;
    }

    /*
    // TEMP:
    for (int i = 0; i < (sizeof(words)/sizeof(words[0])); i++) {
        cout << words[i] << endl;
    }
    */

    // Running Algorithm
    long int num_valid_sentences = 0;
    int n = sizeof(words)/sizeof(words[0]);
    for (long int i = 1; i <= n; i++) {
        generateNumValidSentences(words, n, i, num_valid_sentences);
    }
    
    cout << num_valid_sentences;

    // FOR ERROR TESTING
    /*
    if (num_valid_sentences == 0) {
        cout << num_valid_sentences;
        return 0;
    }
    cout << 2;
    */

    return 0;
}