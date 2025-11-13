/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:20:03 by camerico          #+#    #+#             */
/*   Updated: 2025/11/13 16:12:29 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

// doit parcourir la chaine et emplacer s1 par s2
// s1 est la string qu'on va checher dans la ligne, et s2 est le mot qui va remplacer s1 dans la phrase
std::string str_replace(std::string oldstr, std::string s1, std::string s2)
{
	std::string new_str;
	size_t	pos = 0;
	size_t	found;

	if(oldstr.empty())		//si oldstr est vide, on renvoie la ligne 
		return oldstr;
	
	found = oldstr.find(s1, pos);	//on cherche s1 dans oldstr, a partir de pos (0). on retourne l'index
	while (found != std::string::npos)		//found != npos veut dire qu'on a trouve s1
    {
        // copier le deb de la phrase (avant s1)
        new_str += oldstr.substr(pos, found - pos);
        
        //remplace par s2
        new_str += s2;
        
        // deplace la pos apres s1
        pos = found + s1.length();
        
        //cherche le prochain s1 dans la phrase
        found = oldstr.find(s1, pos);
    }
    
    //reste de la ligne
    new_str += oldstr.substr(pos);
    
    return new_str;
}


int main(int argc, char **argv)
{	
	if (argc != 4)
	{
		std::cerr << "Nb of arguments invalid" << std::endl;
		return 1;
	}
	
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	if (s1.empty())
	{
		std::cout << "s1 empty is not valid" << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str());		//ouvre le fichier en mode lecture
	if(!infile.is_open())
	{
		std::cerr << "Error openning file " << filename << std::endl;
		return 1;
	}
	
	std::string name_new_file = filename + ".replace";		//on cree le fichhier .replace
	std::ofstream outfile(name_new_file.c_str());

	if (!outfile.is_open())
	{
		std::cerr << "Error create file and open " << filename << std::endl;
		infile.close();
		return 1;
	}

	//on lit ligne par ligne et on remplace 

	std::string line;
	while(std::getline(infile, line))
	{
		std::string newline = str_replace(line, s1, s2);
		outfile << newline;

		//on ajoute un retour a la ligne saud si c'est la dernire ligne
		if (!infile.eof())
			outfile << std::endl;
	}
	
	infile.close();		//ferme les 2 fichiers 
	outfile.close();
		
	return 0;
}
