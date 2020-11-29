package tetris;

import java.util.Random;
import java.util.Scanner;


public class Tetris{
	
	private int fieldWidth = 12;
	private int fieldHeight = 20;
	
	
	private char field[][];
	// (x, y)
	//private int[] point = {5, 16};
	private int[] point = {5, 20};
	private int score = 0;
	
	private void initField() {
		field = new char[fieldWidth][fieldHeight];
		for(int width = 0; width < fieldWidth; width++) {
			for(int height = 0; height < fieldHeight; height++) {
				field[width][height] = '-';	
			}
		}
		
	}
	
	// deletes row and pushes every row above one down
	private void deleteRow(int rowNum) {
		for(int x = 0; x < fieldWidth; x++) {
			field[x][rowNum] = '-';
		}
		for(int y = rowNum; y < fieldHeight-1; y++) {
			
			for(int x = 0; x < fieldWidth; x++) {
				field[x][y] = field[x][y+1];
			}
		}
	}
	
	private void checkRows() {
		for(int y = 0; y < fieldHeight; y++) {
			for(int x = 0; x < fieldWidth; x++) {
				if(field[x][y] != '#') {
					break;
				}
					
				if(x == fieldWidth - 1) {
					deleteRow(y);
					score+=100;
				}
			}
		}
	}
	
	private void printField() {
		for(int y = fieldHeight-1; y>=0; y--) {
			for(int x = 0; x < fieldWidth; x++) {
				System.out.print(field[x][y]);
			}
			System.out.print("\n");
		}
	}
	
	private void insertShapeAtPoint(Parts part, boolean reset) {
		int shapeWidth = part.getWidth();
		int shapeHeight = part.getHeight();
		int[][] shape = part.getShape();
		
		int[] fieldPoint = new int[2];
		for(int width = 0; width < shapeWidth; width++) {
			for(int height = 0; height < shapeHeight; height++) {
				// x coordinate
				fieldPoint[0] = point[0] + width;
				// y coordinate
				fieldPoint[1] = point[1] + height;
				if(fieldPoint[0]<fieldWidth && fieldPoint[1]<fieldHeight) {
					if(shape[width][height] == 1) {
						if(reset) {
							field[fieldPoint[0]][fieldPoint[1]] = '-';
						}else {
							field[fieldPoint[0]][fieldPoint[1]] = '#';
						}
					}
				}
				
			}
		}
	}
	
	private boolean moveRightLeftPossible(Parts part, boolean right) {
		int shapeWidth = part.getWidth();
		int shapeHeight = part.getHeight();
		int[][] shape = part.getShape();
		int[] fieldPoint = new int[2];
		
		// if bottom is reached
		if(point[1] - 1 < 0) {
			return false;
		}
		
		if(right) {
			if(point[0] + 1 >= fieldWidth) {
				return false;
			}
			
		}else {
			if(point[0] - 1 < 0) {
				return false;
			}
		}
		
		// look if '1' of shape goes to already set '#'
		for(int width = 0; width < shapeWidth; width++) {
			for(int height = 0; height < shapeHeight; height++) {
				// y coordinate
				fieldPoint[1] = point[1] + height;
				// x coordiinate
				if(right) {
					fieldPoint[0] = point[0] + width +1;
				}else {
					fieldPoint[0] = point[0] + width -1;
				}
				
				if(fieldPoint[0]>=fieldWidth || fieldPoint[1]>=fieldHeight) {
					return false;
				}
				
				// if shape is '#' and field is already set than cant move there
				if(shape[width][height] == 1) {
					if(field[fieldPoint[0]][fieldPoint[1]] == '#') {
						//System.out.printf("%d %d", width, height);
						return false;
					}
				}
				
			}
		}
		
		return true;
	}
	
	private boolean moveDownPossible(Parts part) {
		int shapeWidth = part.getWidth();
		int shapeHeight = part.getHeight();
		int[][] shape = part.getShape();
		int[] fieldPoint = new int[2];
		
		// if bottom is reached
		if(point[1] - 1 < 0) {
			return false;
		}
		
		// look if '1' of shape goes to already set '#'
		for(int width = 0; width < shapeWidth; width++) {
			for(int height = 0; height < shapeHeight; height++) {
				// x coordinate
				fieldPoint[0] = point[0] + width;
				// y coordinate
				// height -height
				fieldPoint[1] = point[1] + height - 1;
				// if already set moving down impossible
				if(fieldPoint[0]<fieldWidth && fieldPoint[1]<fieldHeight) {
					if(shape[width][height] == 1) {
						if(field[fieldPoint[0]][fieldPoint[1]] != '-') {
							//point[1]--;
							return false;
						}
					}
				}		
			}
		}
		return true;
		
	}
	
	
	public Tetris() {
		int random;
		Parts p;
		Scanner myObj = new Scanner(System.in);
		String direction;
		Random ran = new Random();

		
		initField();
		printField();
		while(true) {
			random =  ran.nextInt(6);
			//random = 3;
			p = new Parts(random);
			p.rotateRandomly();
			point[0] = 5;
			point[1] = 20;
			while(true) {
				direction = myObj.nextLine();
				
				if(direction.contentEquals("d")) {
					//this.moveShapeVertically(p, true);
					if(this.moveRightLeftPossible(p, true)) {
						point[0]++;
					}
					
				}else if(direction.contentEquals("a")){
					if(this.moveRightLeftPossible(p, false)) {
						point[0]--;
					}
				}else if(direction.contentEquals("w")) {
					p.rotateRight();
				}else if(direction.contentEquals("c")) {
					System.out.print(this.score);
					continue;
				}
				
				// if moving possible
				if(moveDownPossible(p)) {
					// insert in field
					insertShapeAtPoint(p, false);
					printField();
					// delete old shape out of field
					insertShapeAtPoint(p, true);
					// go one down
					point[1]--;
				}else {
					insertShapeAtPoint(p, false);
					printField();
					//System.out.print("Round over");
					break;
				}
				checkRows();
				
			}
			
		}
		
		
	}

}
