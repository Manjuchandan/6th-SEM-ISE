//package tryStrategy;

public class FTCustomer extends Customer {
	public FTCustomer(String id, String name) {
		super(id, name);
		this.d=new FTCDiscount();
		typeOfCust="First Time Customer";
		// TODO Auto-generated constructor stub
	}
}
