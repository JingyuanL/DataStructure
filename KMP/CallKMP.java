public class CallKMP{
	public static void main(String[] args) {
		String s = args[0];
		String t = args[1];
		KMP kmp = new KMP(s, t);
		int rst = kmp.Compare();
		if(rst == -1){
			System.out.println("No result.");
		}
		else{
			System.out.println("The result is: " + (rst+1));
		}
	}
}
