// 07Keywords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;
//using std::vector;
//using std::string;

int main()
{
	// initializing the needed string and list of strings
	vector<string>::iterator iter;
	vector<string>::const_iterator const_iter;
	vector<string> correct_guesses;
	vector<string> answer;
	string name;
	string guess;
	enum fields { WORD, HINT, NUM_FIELDS };
	int tries = 3;
	int winCount = 0;
	//correct_guesses is the vector of words
	correct_guesses.push_back("goldfish");
	correct_guesses.push_back("jiffy");
	correct_guesses.push_back("ears");
	correct_guesses.push_back("orange");
	correct_guesses.push_back("eat");
	correct_guesses.push_back("bud");
	correct_guesses.push_back("hand");
	correct_guesses.push_back("water");
	correct_guesses.push_back("tree");
	correct_guesses.push_back("cat");

	for (const_iter = correct_guesses.begin(); const_iter != correct_guesses.end(); ++const_iter)
	{
		cout << *const_iter << endl;
	}

	srand(static_cast<unsigned int> (time(0)));


	cout << /*_________            .___       __________                        __                  ___________             .__       .__                   _________.__              .__          __  .__
			\_   ___ \  ____   __ | _ / ____   \______   \_______   ____ _____ | | __ ___________  \__    ___ / ___________ | __ | ____ | __ | ____    ____ / _____ / | __ | _____  __ __ | | _____ _ / | _ | __ | ____   ____
			/ \  \ / / _ \ / __ | / __ \ | | _ / \_  __ \_ / __ \\__  \ | | / // __ \_  __ \   |    |  \_  __ \__  \ |  |/    \|  |/    \  / ___\   \_____  \ |  |/     \|  |  \  | \__  \\   __\  |/  _ \ /    \
			\     \___(<_>) / _ / \  ___ / | | \ | | \ / \  ___ / / __ \ | <\  ___ / | | \ / | | | | \// __ \|  |   |  \  |   |  \/ /_/  >  /        \|  |  Y Y  \  |  /  |__/ __ \|  | |  (  <_> )   |  \
			\______  /\____/\____ |\___  >  |______  / |__|    \___  >____  /__|_ \\___  >__|      |____|   |__|  (____  /__|___|  /__|___|  /\___  /  /_______  /|__|__|_|  /____/|____(____  /__| |__|\____/|___|  /
			\ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \//_____/           \/          \/                \/                    \/*/ endl;

			// intructions for the user down below
	cout << " Welcome to the Code Breaker Training Simulation " << endl;
	cout << " You may now login user " << endl;
	cin >> name;
	cout << "This simulation is used to train new recruits " << endl;
	cout << "try to guess the word, " << name << " you have a max of six tries. " << endl;
	cout << "there will be no hints or external help " << endl;
	cout << "if the correct letters are guessed they will be shown" << endl;
	cout << "if you use all six tries you will be failed " << endl;
	cout << "once you have made three correct answers, you " << endl;
	cout << "will be passed and the program will exit out " << endl;

	// initializing the for loop
	for (int i = 0; i < 3; ++i)
	{
		srand(static_cast<unsigned int> (time(0)));
		int choice = (rand() % correct_guesses.size());
	//	string theWord = correct_guesses[choice];
		//correct_guesses.erase(correct_guesses.begin() + choice);
		//choice = (rand() % choice - 1);
		string theWord = correct_guesses[choice];


		while (guess != theWord && guess != "q" && winCount <= 3)
		{

			//cout << theWord << endl;

			cout << " Enter the answer or q for 'quit'" << endl;
			cin >> guess;

			// quitting / losing
			if (guess == "q" || tries == 0)
			{
				return 0;
			}
			// incorrect guess below
			if (guess != theWord && guess != "q" && guess != "h")
			{
				cout << " Nope, Try again " << endl;
				tries -= 1;
				cout << name << " you have " << tries << " tries left." << endl;
			}
			// win condition below
			if (guess == theWord)
			{
				theWord = correct_guesses[choice];
				tries -= 1;
				winCount += 1;
				cout << "Good job!" << endl;
			}

			correct_guesses.erase(find(correct_guesses.begin(), correct_guesses.end(), theWord));
			//choice = (rand() % choice - 1);

		}

		system("pause");

	}
	cout << "Congratulations User!  You Win!" << endl;
	cout << "Closing out..." << endl;
	system("pause");

	return 0;
}