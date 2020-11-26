#include "Game.h"

//number of stacks
static int N_o_S=3;

void push(struct Stack** head_ref, unsigned int value) {

	/* 1. allocate node */
	struct Stack* new_node = (struct Stack*)malloc(sizeof(struct Stack));

	/* 2. put in value*/
	new_node->L_i = value;

	/* 3. Make next of new node as head and previous as NULL */
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	/* 4. change prev of head node to new node */
	if (*(head_ref) != NULL) {
		(*head_ref)->prev = new_node;
	}

	/* 5. move the head to point to the new node */
	(*head_ref) = new_node;
}

/*draw one stack of class game*/
void draw_stack(Game* game, Stack* st) {
	//draw all elements of stack
	for (Stack* it = st; it != NULL; it = it->next) {
		//insert spaces
		for (unsigned int i = 0; i < ((game->ret_size()) - (it->L_i)); i++) {
			printf(" ");
		}

		for (unsigned int i = 0; i < 2 * it->L_i; i++) {
			printf("#");
		}
		printf("\n");
	}
}


void Game::init(unsigned int sz) {
	this->size = sz;
	
	for (int i = 1; i <= N_o_S; i++) {
		stacks.insert(std::pair<int,Stack*>(i,NULL));
	}

	for (unsigned int i = 0; i < sz; i++) {
		push(&(stacks.begin()->second), this->size-i);
	}	
}


void Game::draw() {
	for (std::map<int, Stack*>::iterator itr = stacks.begin(); itr != stacks.end();itr++) {
		std::cout << "Stack" << itr->first << ":\n";
		draw_stack(this, itr->second);
	}
}


unsigned int Game::pop_from_stack(int choosen_stack) {
	unsigned int k = stacks.find(choosen_stack)->second->L_i;
	stacks.find(choosen_stack)->second = stacks.find(choosen_stack)->second->next;
	return k;
}


void Game::push_stack(unsigned int destination, unsigned int data) {
	push(&(stacks.find(destination)->second), data);
}


void Game::turn(unsigned int src, unsigned int dest) {
	unsigned int l_i = pop_from_stack(src);
	if (stacks.find(dest)->second != NULL) {
		if (stacks.find(dest)->second->L_i < l_i) {
			std::cout << "Move not legal\n";
			push_stack(src, l_i);
			return;
		}
	}
	push_stack(dest, l_i);
}

unsigned int Game::won() {
	
	//take last element 
	Stack* var = this->stacks.find(N_o_S)->second;
	
	for (unsigned int i = 1; i <= this->size; i++) {
		if (var == NULL) {
			return 0;
		}
		//Reihenfolge 1,2,3,...,size;
		if (var->L_i != i) {
			return 0;
		}
		var = var->next;
	}
	return 1;
}

unsigned int Game::choose_stack(int c_b_e) {
	Stack* choosen_stack = NULL;
	int choose = 0, end = 0;

	while (!end) {
		printf("choose stack (0<x<%d):\n",this->size);
		std::cin >> choose;
		if ((choose <= N_o_S && choose >= 1)) {
			end = 1;
		}
		else {
			system("cls");
			this->draw();
			continue;
		}
		//if choosen stack empty (when not allowed)-> continue
		if (c_b_e&&end) {
			break;
		}
		if ((this->stacks.find(choose)->second == NULL && end)) {
			end = 0;
			std::cout << "chosen stack empty\n\n";
		}
		system("cls");
		this->draw();
	}

	return choose;
}



Game::Game(int size) {
	this->init(size);
	this->draw();

	unsigned int source, dest;
	int can_be_empty = 0, counter = 1, l_i;

	while (!this->won()) {
		std::cout << "chose source:\n";
		source = this->choose_stack(can_be_empty);
		std::cout << "source choosen\nChoose destination:\n";
		dest = this->choose_stack(!can_be_empty);
		//printf("destination choosen");
		this->turn(source, dest);
		system("cls");
		this->draw();
		counter++;
	}
	std::cout << "Congratulation you won in " <<counter<< " steps";

}


