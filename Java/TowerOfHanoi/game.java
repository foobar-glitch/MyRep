import java.util.*;
import java.util.Map.Entry; 

//https://www.geeksforgeeks.org/linked-list-in-java/
//https://dbs.cs.uni-duesseldorf.de/lehre/docs/java/javabuch/html/k100100.html

public class game {
	//size of tower
	private int size;
	private HashMap<Integer, LinkedList<Integer>> stacks = new HashMap<Integer,  LinkedList<Integer>>();
	private Scanner reader;
	
	
	private void init(int sz) {
		this.size=sz;
		LinkedList<Integer> aux=new LinkedList<Integer>();
		for(int i=1;i<=this.size;i++) {
			aux.add(i);
			//this.stacks.put(1,this.size-i);
		}
		this.stacks.put(1,aux);
		
		aux=new LinkedList<Integer>();
		for(int i=2;i<=3;i++) {
			this.stacks.put(i,aux);
		}		
	}
	
	private void draw() {
		Iterator<Entry<Integer, LinkedList<Integer>>> it = this.stacks.entrySet().iterator(); 
		LinkedList<Integer> aux=new LinkedList<Integer>();
		//it->ll
		while (it.hasNext()) {
			Map.Entry<Integer, LinkedList<Integer>> entry = (Map.Entry<Integer, LinkedList<Integer>>)it.next();
			System.out.println("Stack "+ (Integer)entry.getKey());
			aux = (LinkedList<Integer>)entry.getValue();
			for (int i = 0; i < aux.size(); i++) {
				for (int k = 0; k < this.size - aux.get(i); k++) {
					System.out.print(" ");
				}
				
				for(int j=0; j<2*aux.get(i);j++) {
					System.out.print("#");
				}
				
				System.out.print("\n");
			}		
		}
	}
	
	private int choose_stack(boolean c_b_e) {
		int choose = 0;
		boolean end=false;
		reader = new Scanner(System.in);
		
		
		while(!end) {
			System.out.printf("choose stack (0<x<4)");
			choose=reader.nextInt();
			if ((choose <= 4 && choose >= 1)) {
				end = true;
			}
			else {
				//system("cls");
				this.draw();
				continue;
			}
			
			if(c_b_e&&end) {
				break;
			}
			
			if(this.stacks.get(choose).isEmpty()&&end) {
				end=false;
				System.out.println("choosen Stack empty");
			}
			//system("cls");
			this.draw();
		}
		return choose;
	}
	
	private boolean won() {
		LinkedList<Integer> aux=new LinkedList<Integer>();
		aux=this.stacks.get(3);
		
		for (int i = 0; i < this.size; i++) {
			try {
				if(aux.get(i)!=i+1) {
					return false;
				}
			}
			catch(IndexOutOfBoundsException e){
				return false;
			}
		}
		return true;
	}
	
	private void turn(int src, int dst) {
		//stack
		int i_src=this.stacks.get(src).pop();
		int i_dst;
		
		try {
			i_dst=this.stacks.get(dst).pop();
			this.stacks.get(dst).push(i_dst);
		}
		//if stack empty you can always add element
		catch(NoSuchElementException f){
			i_dst=this.size+1;
		}
		
		
		
		if(!this.stacks.get(dst).isEmpty()) {
			if(i_dst<i_src) {
				System.out.println("Move not legal");
				this.stacks.get(src).push(i_src);
				return;
			}
		}
		
		
		LinkedList<Integer> aux=new LinkedList<Integer>();
		
		aux.add(i_src);
		while(!this.stacks.get(dst).isEmpty()) {
			aux.add(this.stacks.get(dst).pop());
		}
		
		this.stacks.put(dst, aux);
	}
	
	
	public game(int my_size) {
		// TODO Auto-generated constructor stub
		this.init(my_size);
		this.draw();
		
		
		int source, destination,counter=0;
		while(!this.won()) {
			System.out.println("Enter source:");
			//source must contain element
			source=this.choose_stack(false);
			System.out.println("Enter destination:");
			//destination can be empty
			destination=this.choose_stack(true);
			
			this.turn(source, destination);
			//system("cls");
			this.draw();
			counter++;
		}
		System.out.println("Congratulation you won in "+(Integer)counter+" Steps");	
	}
}
