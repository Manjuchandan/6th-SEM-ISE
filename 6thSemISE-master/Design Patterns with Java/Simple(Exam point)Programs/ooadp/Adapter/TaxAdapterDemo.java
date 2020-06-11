public class TaxAdapterDemo {
	public static void main(String[] args) {
		GST gst = new GST();
		Item i1 = new Item("Btwin Roackroder 340", 545000.0, gst);
		i1.setQunatity(3);
		i1.printPrice();
		i1.setTax(new MTA());
		i1.printPrice();
			}

}
