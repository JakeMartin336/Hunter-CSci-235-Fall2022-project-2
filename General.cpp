// Jacob Martin
// 9/23/2022
// General.cpp
// Project 2 - create general class that lets user react to a post

#include "General.hpp"

General::General(std::string g_name, std::string g_body, std::string g_acct) : 	Post(g_name, g_body, g_acct) //constructor
{
	for (int i = 0; i < 6; i++) //assigning all values in array to 0
	{
		arr[i] = 0;
	}
}

bool General::reactToPost(const Reactions& react)
{
	bool final = false;
	switch (react) //test the input given and if its valid then add a vote to the array
	{
		case LIKE:
			arr[0] += 1;
			final = true;
			break;
		case DISLIKE:
			arr[1] += 1;
			final = true;
			break;
		case LAUGH:
			arr[2] += 1;
			final = true;
			break;
		case WOW:
			arr[3] += 1;
			final = true;
			break;
		case SAD:
			arr[4] += 1;
			final = true;
			break;
		case ANGRY:
			arr[5] += 1;
			final = true;
			break;
		default:
			break;
	}
	return final;
}

void General::getReactions() const
{
	for (int i = 0; i < 6; i++) //going through entire array and printing out the values stored 
	{
		switch (i)
		{
			case 0:
				std::cout << "Like : " << arr[i] << " | ";
				break;
			case 1:
				std::cout << "Dislike : " << arr[i] << " | ";
				break;
			case 2:
				std::cout << "Laugh : " << arr[i] << " | ";
				break;
			case 3:
				std::cout << "Wow : " << arr[i] << " | ";
				break;
			case 4:
				std::cout << "Sad : " << arr[i] << " | ";
				break;
			case 5:
				std::cout << "Angry : " << arr[i];
				break;
			default:
				break;
		}
	}
}

void General::displayPost() const //print display in format assigned
{
	std::cout << std::endl;
	Post::displayPost();
	getReactions();
	std::cout << std::endl;
}
