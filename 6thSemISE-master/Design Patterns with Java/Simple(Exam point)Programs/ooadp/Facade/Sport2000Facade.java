public class Sport2000Facade {
	
	ItemPurchased oItempurchased; 
	Sport2000ProcessSales oProcesssales; 
	
	Sport2000Facade(boolean giftCert, float billAmount){ 
		oItempurchased = new ItemPurchased(); 
		int numItems = oItempurchased.getTypeCount(); 
		System.out.println("Number of Items Purchased is "+numItems); 
		System.out.println("Gift Certificate exists "+giftCert); 
		oProcesssales = new Sport2000ProcessSales(giftCert, numItems, billAmount); 
	}
	
	
	void displayItemsPurchased() { 
		oItempurchased.showItems(); 
	}
		
	
	void calculateAmountToPay() { 
		oProcesssales.processSale(); 
	}
}
