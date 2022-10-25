
public class myNode {

	//--------------------------------------------------
	// Attributes
	//--------------------------------------------------
	private int myInfo;
	private myNode myNext;
	
	//--------------------------------------------------
	// Constructor
	//--------------------------------------------------
	public myNode(int i, myNode n){
		this.myInfo = i;
		this.myNext = n;
	}
	
	//--------------------------------------------------
	// Get methods
	//--------------------------------------------------
	public int get_my_info(){
		return this.myInfo;
	}
	
	public myNode get_my_next(){
		return this.myNext;
	}
	
	//--------------------------------------------------
	// Set methods
	//--------------------------------------------------
	public void set_my_info(int i){
		this.myInfo = i;
	}
	
	public void set_my_next(myNode n){
		this.myNext = n;
	}
	
}
