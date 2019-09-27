/*
    Program to create a quiz for others to take. Can create up to 2 questions.
    Questions are multiple choice with 4 answer choices. **Currently only accepts 1 word answers.**
*/

#include<iostream>
#include<string>

using namespace std;

struct additional_question {
    string question;
    string ans1;
    string ans2;
    string ans3;
    string ans4;
    char realans;
};

void print_question(string q1, string a1, string a2, string a3, string a4) {

    cout << endl << q1 << endl << "a. " << a1 << endl << "b. " << a2 << endl << "c. " << a3 << endl << "d. " << a4 << endl;

}

void print_question2(additional_question q) {

    cout << endl << q.question << endl << "a. " << q.ans1 << endl << "b. " << q.ans2 << endl << "c. " << q.ans3 << endl << "d. " << q.ans4 << endl;

}

string set_question(){

    string q1 = "";

    cout << "Enter a question:" << endl << endl;
    getline(cin,q1);
    return q1;

}

additional_question add_question() {

    additional_question q;
    cin.ignore();
    q.question = set_question();
    cout << endl << "Enter four possible answers:" << endl << endl;
    cin >> q.ans1 >> q.ans2 >> q.ans3 >> q.ans4;
    cout << endl << "Set the desired answer (a/b/c/d):" << endl;
    cin >> q.realans;
    return q;
}

int check_answer(char a, char d) {
    if(a==d)
        return 1;
    else
        return 0;
}

int main(){

    string another_question = "";

    int score = 0;
    int l = 0;

    char answer1 = 0;
    char answer2 = 0;
    char desired_answer = 0;

    additional_question question1;
    additional_question question2;

    question1.question = set_question();                        // set initial question

    cout << endl << "Enter four possible answers:" << endl << endl;
    cin >> question1.ans1 >> question1.ans2 >> question1.ans3 >> question1.ans4; // only accepts 1 word answers currently

    cout << endl << "Set the desired answer (a/b/c/d):" << endl;
    cin >> question1.realans;

label:
    cout << endl << "Add another question?" << endl;
    cin >> another_question;
    l = another_question.length();
    for (int i=0; i<l; i++)
        another_question[i] = tolower(another_question[i]);     // convert variations of "Yes" to yes and "No" to no

    if(another_question=="yes")
        question2 = add_question();
    else if(another_question!="no"){
        cout << "That is not a valid answer" << endl;
        goto label;
        }

    print_question(question1.question, question1.ans1, question1.ans2, question1.ans3, question1.ans4); // calls function to print question

    cin >> answer1;
    desired_answer = question1.realans;

    score = check_answer(answer1, desired_answer);            // calls function to evaluate score of first question

    if(another_question=="yes"){
            print_question2(question2);
            cin >> answer2;
            desired_answer = question2.realans;
    }

    score = score + check_answer(answer2, desired_answer);    // calls function to evaluate score of second question
    cout << "You got " << score << " question(s) right!" << endl << endl;

    return 0;
}
