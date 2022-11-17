// Jacob Martin
// 9/23/2022
// Promotional.cpp
// Project 2 - create promotional class that lets user create a post with a valid link

#include "Promotional.hpp"

Promotional::Promotional(std::string p_name, std::string p_body, std::string p_acct, std::string link) : Post(p_name, p_body, p_acct) //passing constructor to the parent class constructor
{
	setLink(link); //passing url parameter to the setLink method to check if the parameter is valid
}

std::string Promotional::getLink() const
{
	return url; //returning data member
}

bool Promotional::setLink(const std::string& link)
{
	//std::regex reg("^(http[s]?:\/\/www\.)[a-zA-Z0-9]+\.[a-zA-Z0-9]{2,}$");
	//std::regex reg("(http[s]?://www\.)[^ \.\\s]+\.[^ \.\\s]{2,}"); 
	std::regex reg("^(https:\\/\\/www\\.|http:\\/\\/www\\.)[A-Za-z0-9!\\_\\-!@$\\^&*]+\\.[a-zA-Z]{2,}$"); //creating a reg object that checks for https://www. or http://www. and if there are enough chars after the .
	if (regex_match(link, reg) == true)//using regex to check if the reg object matches the parameter passed exactly
	{
		url = link; //if it matches then assign parameter to url data member and return true
		return true;
	}
	else
	{
		url = "Broken Link"; //if it doesnt match then return false and set the link to a broken link
		return false;
	}
}

void Promotional::displayPost() const //printing Promotional class in the format that was assigned
{
	std::cout << std::endl;
	Post::displayPost(); 
	std::cout << getLink() << std::endl;
}
