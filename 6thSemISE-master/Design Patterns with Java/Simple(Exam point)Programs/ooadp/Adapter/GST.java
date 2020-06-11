public class GST implements CalcTax {
	double tax_amount=0.0;
	public double taxAmount(String item, int qty, double price) {
		tax_amount = price*qty*0.25f;
		return tax_amount;
	}

}
