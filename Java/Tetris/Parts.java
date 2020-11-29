package tetris;

import java.util.Random;

public class Parts {
	// (x, y)
	// index of array := x
	// bottom to top
	
	/*
	 * #
	 * #
	 * #
	 * #
	 */
	
	/*
	 * ##
	 * ##
	 */
	
	/*
	 * #
	 * #
	 * ##
	 */
	
	/*
	 *  #
	 *  #
	 * ##
	 */
	
	/*
	 * 	#
	 * ###
	 */
	
	
	/*
	 * #
	 * ## 
	 *  #
	 */
	
	private int[][][] allShapes = new int[][][] {
		{{1, 1, 1, 1}},			 // stick
		{{1, 1}, {1, 1}}, 		 // square
		{{1, 1, 1}, {1, 0, 0}},	 // l
		{{1, 0, 0}, {1, 1, 1}},  // l-
		{{1, 0}, {1, 1}, {1, 0}},// T-shape 
		{{0, 1, 1}, {1, 1, 0}}	 // S
	};
	
	
	private int[][] chosenShape;
	
	
	private void chooseTheShape(int choose) {
		try {
			chosenShape = allShapes[choose];
		} catch(ArrayIndexOutOfBoundsException ar) {
			System.out.printf("Shape %d doesn't exist", choose);
			System.exit(1);
		}
		
		
	}
	
	// swaps the x and y coordinates
	
	private int[][] swapXandY(int[][] array1) {
		int width = array1.length;
		int height = array1[0].length;
		
		int[][] tmp = new int[height][width];
		
		for(int x = 0; x < width; x++) {
			for(int y = 0; y < height; y++) {
				tmp[y][x] = array1[x][y];
			}
		}
		array1 = tmp;
		return array1;
	}
	
	public void rotateRight() {
		int width = chosenShape.length;
		int height = chosenShape[0].length;
		
		int[][] tmp = new int[width][height];
		// mirror horizontally
		for(int x = 0; x < width; x++) {
			for(int y = 0; y < height; y++) {
				tmp[x][y] = chosenShape[width - x - 1][y];
			}
		}
		
		chosenShape = swapXandY(tmp);
	}
	
	
	private void rotateLeft() {
		int width = chosenShape.length;
		int height = chosenShape[0].length;
		
		int[][] tmp = new int[width][height];
		// mirror horizontally
		for(int x = 0; x < width; x++) {
			for(int y = 0; y < height; y++) {
				tmp[x][y] = chosenShape[x][height - y -1];
			}
		}
		
		chosenShape = swapXandY(tmp);
	}
	
	
	
	private void printShape() {
		int width = chosenShape.length;
		int height = chosenShape[0].length;
		char miniField[][] = new char[width][height];
		
		
		for(int x = 0; x < width; x++) {
			for(int y = 0; y < height; y++) {
				if(chosenShape[x][y] == 1) {
					miniField[x][y] = '#';
				}else{
					miniField[x][y] = ' ';
				}
				
			}
		}
		
		
		for(int y = height-1; y>=0; y--) {
			for(int x = 0; x < width; x++) {
				System.out.print(miniField[x][y]);
			}
			System.out.print("\n");
		}	
		
	}
	
	public Parts(int choose) {
		chooseTheShape(choose);
	}
	
	public void rotateRandomly() {
		Random ran = new Random();
		int random = ran.nextInt(4);
		for(int i = 0; i < random; i++) {
			rotateRight();
		}
	}
	
	public int[][] getShape() {
		return chosenShape;
	}
	
	public int getWidth() {
		return chosenShape.length;
	}
	
	public int getHeight() {
		return chosenShape[0].length;
	}
	
	
	

}
