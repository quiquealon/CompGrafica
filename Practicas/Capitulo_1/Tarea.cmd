Escreva os procedimentos inp to ndc, ndc to user, user to ndc e ndc to dc, que transformam dados entre os vários sistemas de coordenadas, conforme ilustrado na Figura 1.3. Repita o exercı́cio assumindo que o intervalo de variação do sistema NDC vai de:


-1 a 1


void inp_to_ndc(int dcx, int dcy){
	ndcx = dcx/ndhm1;
	ndcy = dcy/ndvm1;
}

void ndc_to_user(double ndcx,double ndcy){
	x = ndcx * (1-(-1)) + (-1);
	y = ndcy * (1-(-1)) + (-1);
}

void user_to_ndc(double x, double y){
	ndcx = (x-(-1))/(1-(-1));
	ndcy = (x-(-1))/(1-(-1));
}

void ndc_to_dc(double ndcx, double ndcy){
	dcx = round(ndcx*ndhm1);
	dcy = round(ndcy*ndhm1);
}



0 a 100



void inp_to_ndc(int dcx, int dcy){
	ndcx = dcx/ndhm1;
	ndcy = dcy/ndvm1;
}

void ndc_to_user(double ndcx,double ndcy){
	x = ndcx * (100-(0)) + (0);
	y = ndcy * (100-(0)) + (0);
}

void user_to_ndc(double x, double y){
	ndcx = (x-(0))/(100-(0));
	ndcy = (x-(0))/(100-(0));
}

void ndc_to_dc(double ndcx, double ndcy){
	dcx = round(ndcx*ndhm1);
	dcy = round(ndcy*ndhm1);
}
