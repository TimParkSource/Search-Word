#ifndef WORDLIST_H
#define WORDLIST_H

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <sstream>
#include <typeinfo>
#include "iterator.h"
using namespace std;

class WordList{
private:
	/**
	*Stores the word from text file
	*/
	string Word;
	/**
	*Stores the line numbers (as integers) on which the Word is found
	*/
	SinglyLinkedList<int>  LineNumList;
public:
	const SinglyLinkedList<int> getList();
	string getWord();
	void setList(SinglyLinkedList<int> L);   
	void setWord(string W); 
	static void convertToLowerCase(string & text);
	WordList(const string & wrd = " ", SinglyLinkedList<int> Line = SinglyLinkedList<int>());
	/**
	*Reads data from the file or keyboard to fill the WordList object
	*/
	friend istream & operator >>(istream & in, WordList& WL)  // probably need to change this...
	{
		in>>WL.Word; 
		return in;
	}
	/**
	*Writes data to the file or to screen to print the WordList object
	*/
	friend ostream & operator <<(ostream & out, const WordList& WL)  // have to change this  because number of characters is irrelevant..
	{
		out<<WL.Word<< " ";
		WL.LineNumList.printForward(out);
		return out;
	}
	friend bool operator < (const WordList & left, const WordList & right)  // is this right?
	{
		return left.Word<right.Word;
	}
	friend bool operator > (const WordList & left, const WordList & right)
	{
		return left.Word>right.Word;
	}
	friend bool operator == (const WordList & left, const WordList & right)
	{
		return left.Word == right.Word;
	}
};


#endif