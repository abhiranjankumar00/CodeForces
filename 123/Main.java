//-----------
//----lost---
//-----------

import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

class Main
{
	public static void main(String [] args) throws Exception
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		Stack stc;
		String msg = "";
		boolean found = false;

		for(int i = 1; i <= N; i++) {
			String st = br.readLine();
			st = st.trim();

			if(st.length() == 0)
				continue;

			if(st.substring(0, 2).equals("th")) {
				found = true;
				msg = st.split("( ")[2];
				System.out.println(msg);
			}
		}
	}
}

