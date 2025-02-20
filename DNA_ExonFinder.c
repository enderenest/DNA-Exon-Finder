#include <stdio.h>

char dna_to_rna(char dna){
	switch(dna){
		case 'A': return 'U';
		case 'T': return 'A';
		case 'G': return 'C';
		case 'C': return 'G';
		default: return ' ';
	}
}

char converter(char n1, char n2, char n3) {
    if (n1 == 'U') {
        if (n2 == 'U') {
            if (n3 == 'U' || n3 == 'C') {
                return 'f'; /*Phenylalanine*/ 
            } else {
                return 'l'; /*Leucine*/ 
            }
        } else if (n2 == 'C') {
            return 's'; /*Serine*/ 
        } else if (n2 == 'A') {
            if (n3 == 'U' || n3 == 'C') {
                return 'y'; /*Tyrosine*/ 
            } else {
                return 'x'; /*Stop*/ 
            }
        } else if (n2 == 'G') {
            if (n3 == 'U' || n3 == 'C') {
                return 'c'; /*Cysteine*/ 
            } else if (n3 == 'G') {
                return 'w'; /* Tryptophan*/
            }
            else{
                return 'x'; /*Stop*/
            }
        }
    } else if (n1 == 'C') {
        if (n2 == 'U') {
            return 'l'; /*Leucine*/ 
        } else if (n2 == 'C') {
            return 'p'; /*Proline*/ 
        } else if (n2 == 'A') {
            if (n3 == 'U' || n3 == 'C') {
                return 'h'; /*Histidine*/ 
            } else {
                return 'q'; /*Glutamine*/ 
            }
        } else if (n2 == 'G') {
            return 'r'; /*Arginine*/ 
        }
    } else if (n1 == 'A') {
        if (n2 == 'U') {
            if (n3 == 'G') {
                return 'm'; /*Methionine*/ 
            } else {
                return 'i'; /*Isoleucine*/ 
            }
        } else if (n2 == 'C') {
            return 't'; /*Threonine*/ 
        } else if (n2 == 'A') {
            if (n3 == 'U' || n3 == 'C') {
                return 'n'; /*Asparagine*/ 
            } else {
                return 'k'; /*Lysine*/ 
            }
        } else if (n2 == 'G') {
            if (n3 == 'U' || n3 == 'C') {
                return 's'; /*Serine*/ 
            } else {
                return 'r'; /*Arginine*/ 
            }
        }
    } else if (n1 == 'G') {
        if (n2 == 'U') {
            return 'v'; /*Valine*/ 
        } else if (n2 == 'C') {
            return 'a'; /*Alanine*/ 
        } else if (n2 == 'A') {
            if (n3 == 'U' || n3 == 'C') {
                return 'd'; /*Aspartic Acid*/ 
            } else {
                return 'e'; /*Glutamic Acid*/ 
            }
        } else if (n2 == 'G') {
            return 'g'; /* Glycine*/
        }
    }

    return 'E'; /*ERROR*/
}

int test_exon(int i, int t, int m, char middle_exon[], char rna[]);
int stop_codon_index(int i, char rna[]);
int last_amino(int i, char amino[]);
int len(int i, char middle_exon[], int p);
int main() {
    char dna[3001];
    char rna[3001];
    char amino[2901];
    int i1s=0;
    int i1e=0;
    int i2s=0;
    int i2e=0;
    int i=0;
    int j=0;
    int m=0;
    int k=0;
    int t;
    int p=0;
    char middle_exon[500];
    char x;

    
    
    for (i=0; i<3001; ){
        x = getchar();
            if (x=='.'){
                dna[i]='.';
                i++;
                break;
            }
            else if (x=='A' || x=='T' || x=='G' || x=='C'){
                dna[i]=x;
                i++;
            }
            else
                continue;
    }

	for (i=0; i<3001; i++){
	    if (dna[i]=='.'){
	        rna[i]='.';
	        break;
	    }
	   else{
		    rna[i]=dna_to_rna(dna[i]);
		    /*printf("%c", rna[i]);*/
	   }
	}
	/*printf("\n");*/
	
	for (i=0; i<2901; ){
        x = getchar();
            if (x=='.'){
                amino[i]='.';
                i++;
                break;
            }
            else if (x=='g' || x=='a' || x=='v' || x=='i' || x=='l' || x=='s' || x=='t' || x=='p' || x=='d' || x=='e' || x=='k' || x=='r' ||x=='n' || x=='q' || x=='c' || x=='m' || x=='w' ||x=='f' || x=='y' || x=='h'){
                amino[i]=x;
                /*printf("%c",amino[i]);*/
                i++;
            }
            else
                continue;
	}
	/*printf("\n");*/
	
    i=0;
	j=0;
	
	while(i<3001 && j<2900){
	    if (converter(rna[i],rna[i+1],rna[i+2])==amino[j]){
	        i+=3;
	        j+=1;
	    }
	    else{
	        i1s=i;
	        break;
	    }
	}
	
	m = stop_codon_index(0,rna);
    k=last_amino(0, amino);
    
    while(m>0 && k>0){
	    if (converter(rna[m-2],rna[m-1],rna[m])==amino[k]){
	        m-=3;
	        k-=1;}
	    else{
	        i2e=m;
	        break;}
    }
    
    if (j-k>=1){
        if (j-k==1){
        for (t=i; i<=t && t<=m; t++){
            if (converter(rna[t], rna[t+1], rna[t+2]) == amino[j-1]){
                i1s=i1s-3;
                i1e=t-1;
                i2s=t+3;
                break;
            }
            else if (converter(rna[t], rna[t+1], rna[t+2])==amino[k+1]){
                i2e=i2e+3;
                i1e=t-1;
                i2s=t+3;
                break;
            }
        }
    }
        else if (j-k>1){
            while (j>k){
                t=i;
                if (j-k==1){
                    for (t=i; i<=t && t<=m; t++){
                        if (converter(rna[t], rna[t+1], rna[t+2]) == amino[j-1]){
                            i1s=i1s-3;
                            i1e=t-1;
                            i2s=t+3;
                            break;
                        }
                        else if (converter(rna[t], rna[t+1], rna[t+2])==amino[k+1]){
                            i2e=i2e+3;
                            i1e=t-1;
                            i2s=t+3;
                            break;
                        }
                    }
                }
                else if (j-k>1){
                    k++;
                    i2e-=3;
                }
            }
        }
    }
    
    else{
        for (t=0; ;t++){
            if (j<=k){
                middle_exon[t]=amino[j];
                j++;
            }
            else{
                middle_exon[t]='.';
                break;
            }
        }
        t=0;
        while (i<=m){
            if (converter(rna[i],rna[i+1],rna[i+2])==middle_exon[t] && test_exon(i, t, m, middle_exon, rna)==1){
                if (i1e==0)
                    i1e=i-1;
                    i2s=(i1e + 3 * len(0,middle_exon, p)) + 1;
                t+=1;
                i+=3;
            }
                
            else if (converter(rna[i],rna[i+1],rna[i+2])==middle_exon[t] && middle_exon[t+1]=='.'){
                if (i1e==0)
                    i1e=i-1;
                i2s=i+3;
                break;
            }
            else{
                i+=1;
            }
        }
        
    }
    
    
    if (i1e==0 || i2e==0 || i1s==0 || i2s==0 || m==0){
        printf("NONE");
    }
    else{
        printf("%d %d %d %d",i1s,i1e,i2s,i2e);
    }

    
    

    return 0;
}

int stop_codon_index(int i, char rna[]){
	while (i<3001){
        if ((rna[i+3]=='.') && ((rna[i]=='U' && rna[i+1]=='G' && rna[i+2]=='A') || (rna[i]=='U' && rna[i+1]=='A' && rna[i+2]=='A') || (rna[i]=='U' && rna[i+1]=='A' && rna[i+2]=='G')))
            return i-1;
        else if (rna[i]=='.'){
			return 0;
		}
        else{
            i+=1;
        }
	}
	return 0;
}

int last_amino(int i, char amino[]){
    while (i<2901){
        if (amino[i]=='.')
            return i-1;
        else{
            i+=1;
        }
	}
	return 0;
}

int test_exon(int i, int t, int m, char middle_exon[], char rna[]){
    while(i<=m || t!='.'){
    if (middle_exon[t+1]=='.' && converter(rna[i],rna[i+1],rna[i+2])==middle_exon[t]){
        return 1;
    }
    else if (middle_exon[t+1]!='.' && converter(rna[i],rna[i+1],rna[i+2])==middle_exon[t]){
        t+=1;
        i+=3;
    }
    else{
        i+=1;
        t=0;
        return 0;
    }
}
return 0;
}

int len(int i, char middle_exon[], int p){
    p=0;
    while(middle_exon[i]!='.'){
        p=p+1;
        i+=1;
    }
    return p;
}