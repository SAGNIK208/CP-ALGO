int *kmpArray(string &pattern){

	int index = 0,i =1;

	int *lps = new int[pattern.size()];

	lps[0] = 0;

	while(i<pattern.size()){

		if(pattern[i] == pattern[index]){
			lps[i] = index + 1;
			i++;
			index++;
		}
		else{
			if(index!=0){
				index = lps[index-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}

	return lps;
}

bool kmpAlgo(string text,string pattern){


	int i = 0,j = 0;

	int *lps = kmpArray(pattern);

	while(i < text.size() && j < pattern.size()){

		if(text[i] == pattern[j]){
			i++;
			j++;
		}
		else{

			if(j!=0){
				j = lps[j-1];
			}
			else{
				i++;
			}
			
		}
	}

	if(j == pattern.size()) return true;

	return false;


}