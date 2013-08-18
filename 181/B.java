//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

class Main
{
	boolean isNeigh[][], vis[];
	int cnt, N, M;
	void dfs(int u) {
		if(vis[u])
			return;
		vis[u] = true;
		cnt++;
		for(int i = 0; i < N; i++)
			if(isNeigh[u][i])
				dfs(i);
	}
	void dfs1(int u) {
		if(vis[u])
			return;
		vis[u] = true;
		cnt++;
		write(u+1, "");
		for(int i = 0; i < N; i++)
			if(isNeigh[u][i])
				dfs1(i);
	}
	void solve() {
		N = getInt(); M = getInt();
		isNeigh = new boolean[N][];
		vis = new boolean[N];
		int count[] = new int[4];
		for(int i = 0; i < N; i++)
			isNeigh[i] = new boolean [N];

		for(int i = 0; i < M; i++) {
			int u = getInt()-1, v = getInt()-1;
			isNeigh[u][v] = isNeigh[v][u] = true;
		}
		ArrayList <Integer> ar = new ArrayList <Integer>();

		for(int i = 0; i < N; i++) {
			cnt = 0;
			dfs(i);
			debug(cnt);
			if(cnt>3) {
				writeln(-1);
				return;
			}
			if(cnt == 1)
				ar.add(i);
			count[cnt]++;
		}
		debug(count);
		if(count[1] != count[2]) {
			writeln(-1);
			return;
		}

		Arrays.fill(vis, false);
		for(Integer x: ar)
			vis[x] = true;
		int idx = 0;
		for(int i = 0; i < N; i++) if(!vis[i]){
			cnt = 0;
			dfs1(i);
			if(cnt == 2)
				writeln(ar.get(idx++)+1);
			else
				writeln("");
		}

	}
	public static void main(String [] args) throws Exception
	{
		initShinChanNohara();

		new Main().solve();
	}

//================================================================
	static BufferedReader br;
	static StringTokenizer strTok;

	static void initShinChanNohara() {
		br = new BufferedReader(new InputStreamReader(System.in));
		strTok = null;
	}

	static void initShinChanNohara(String file) {
		try {
			br = new BufferedReader(new FileReader(file));
			strTok = null;
		}
		catch(FileNotFoundException e) {
			writeln(e);
		}
	}

	static String getLine() {
		try {
			String st = br.readLine();
			return st;
		}
		catch(IOException e) {
			return null;
		}

	}

	static String getToken() {
		while(strTok == null || strTok.hasMoreTokens() == false) {
			String st = getLine();
			if(st == null)
				return null;
			strTok = new StringTokenizer(st);
		}
		return strTok.nextToken();
	}

	static int getInt() {
		return Integer.parseInt(getToken()); 
	}
	static double getDouble() {
		return Double.parseDouble(getToken());
	}
	static long getLong() {
		return Long.parseLong(getToken());
	}
	
	static void write(Object ... ob) {
		for(int i = 0; i < ob.length; i++) {
			if(i > 0)
				System.out.print(" ");
			System.out.print(ob[i]);
		}
	}
	static void writeln(Object ... ob) {
		write(ob);
		System.out.println();
	}
	static void debug(Object ... ob) {
		System.out.println(Arrays.deepToString(ob));
	}
}

