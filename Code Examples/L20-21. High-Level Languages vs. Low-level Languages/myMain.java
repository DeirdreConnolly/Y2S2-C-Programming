
import java.util.Scanner;

public class myMain {
		
	//-------------------------------------
	//	MAIN method 
	//-------------------------------------	
	public static void main(String[] args) {
		myNode head = new myNode(5, null);
		head = new myNode(4, head);
		head = new myNode(3, head);		
	
		System.out.println(head.get_my_info());
		
		head = new myNode(7, null);
		System.out.println(head.get_my_info());
		
	}
		
}
