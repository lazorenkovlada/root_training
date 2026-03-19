void read_kate() {
 TFile *file = new TFile("my_secret_data.root", "READ");
 TH1F *hKate = (TH1F*)file->Get("h_signal");
 TCanvas *c1 = new TCanvas("c1", "Kate's hist", 1000, 1000);
 hKate->SetLineColor(kRed); 
 hKate->Draw();
 c1->SaveAs("kate's_hist.png");
}
