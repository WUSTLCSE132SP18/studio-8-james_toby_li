package studio8;

import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;
// TODO: Develop an algorithm to count steps in accelerometer data
//    Major steeps:
//       1. Create a class and main method.
//       2. Using a Scanner and File object, read data from your .csv file.
//       3. Develop and test algorithms to count the "peaks" in the data.
public class TestScanner{
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("C:\\Users\\toby\\Desktop\\123.csv.txt"));
		sc.useDelimiter(",");
		while(sc.hasNext()) {
			System.out.print(sc.next()+"|");
		}
		sc.close();
	}
}