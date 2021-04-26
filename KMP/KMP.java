public class KMP{
	public String s;
	public String t;
	public int[] next;
	public KMP(String s0, String s1){
		this.s = s0;
		this.t = s1;
	}
	
	private int GetNext(int m){
		char tempi, tempj;
		int rtn = m-1;
		boolean jug = false;
		if(rtn != -1){
			rtn = 0;
			for(int n = m-1; n > 0; --n){
				for(int i = 0; i < n; ++i){
					tempi = t.charAt(i);
					tempj = t.charAt(m-n+i);
					if(tempi==tempj){
						if(i == n-1){
							rtn = n;
							jug = true;
						}
					}
					else{
						break;
					}
				}
				if(jug){
					break;
				}
			}
		}
		return rtn;
	}

	private void InitNextArray(){
		next = new int[this.t.length()];
		for(int i = 0; i < this.t.length(); ++i){
			next[i] = GetNext(i);
		}
	}
	
	public int Compare(){
		int rtn = -1;
		char tempi, tempj;
		boolean jug = true;
		InitNextArray();
		int i = 0, j = 0;
		while(jug){
			tempi = s.charAt(i);
			tempj = t.charAt(j);
			if(tempi != tempj){
				if(next[j] == -1){
					++i;
				}
				else{
					j = next[j];
				}
			}
			else{
				if(j == t.length() - 1){
					rtn = i-j;
					jug = false;
				}
				else if(s.length() - i < t.length() - j){
					jug = false;
				}
				++i; ++j;
			}
		}
		return rtn;
	}
}
