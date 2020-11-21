#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

struct Stack
{
	unsigned int L_i;
	Stack * next;
	Stack * prev;
};


class Game {
private:
	//size = number of towers
	unsigned int size;
	//int number of stacks
	std::map<int, Stack*> stacks;

	void init(unsigned int);
	void draw();
	unsigned int choose_stack(int);
	unsigned int pop_from_stack(int);
	void push_stack(unsigned int, unsigned int);
	void turn(unsigned int, unsigned int);
	unsigned int won();

public:
	int ret_size() { return this->size; };
	Game(int);
};