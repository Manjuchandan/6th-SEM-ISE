public class FacadeDemo {
	public static void main(String[] args) {
		
		float billAmount = (float) 1240.50;  
		Sport2000Facade fc = new Sport2000Facade(true, billAmount); 
		
		fc.calculateAmountToPay();
		fc.displayItemsPurchased(); 
		
		
	}

}
