void generate() {
 TF1 *myFunc = new TF1("myFunc", "expo(0) + gaus(2)", 0, 10);// перше це назва, друге це шаблон формули expo(0) означає шукати параметри для спадаючої комірки починаючи з 0(тобто 0 і 1), gaus(2) означає шукати параметри починаючи з 2го індексу, 0 і 10 це межі по X
 myFunc->SetParameter(0, 7.0);// висота фону на початку це моє А
 myFunc->SetParameter(1, -0.9);//Швидкість спадання це моє B
 myFunc->SetParameter(2, 191);//Висота піку (моє С)
 myFunc->SetParameter(3, 5.1);//Координата піку по Х (моє D)
 myFunc->SetParameter(4, 1.1);//Ширина піку (моє E)
 TH1F *h1 = new TH1F("vlada_hist", "My hist;Energy;Events", 100, 0, 10);
 h1->FillRandom("myFunc", 15000);//заповнюємо 1500 випадковими подіями
 //малюємо
 TCanvas *c1 = new TCanvas("c1", "Canvas", 800, 600);
 h1->SetFillColor(38);
 h1->Draw();
 TFile *file = new TFile("vlada_ABCDE.root", "RECREATE");
 h1->Write();
 file->Close();
 cout << "Файл vlada_ABCDE.root створено." << endl;
}
