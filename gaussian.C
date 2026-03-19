void gaussian() {
    // Створюємо полотно
    TCanvas *c1 = new TCanvas("c1", "Gaussian Distribution", 800, 600);

    // від -5 до 5 по X, від 0 до 1.0 по Y
    TH1F *frame = c1->DrawFrame(-5, 0, 5, 1.0);
    frame->SetTitle("Gaussian Distribution; x; #varphi_{#mu,#sigma^{2}}(x)");

    // ROOT просить звичайну сигму, тому беремо корінь
    // Слово "true" в кінці каже ROOT-у малювати нормалізовану формулу 
    TF1 *g1 = new TF1("g1", "TMath::Gaus(x, 1, sqrt(0.3), true)", -5, 5);
    g1->SetLineColor(kGreen);
    g1->SetLineWidth(2);
    g1->Draw("SAME"); // Малюємо поверх нашої рамки

    TF1 *g2 = new TF1("g2", "TMath::Gaus(x, -1, sqrt(0.9), true)", -5, 5);
    g2->SetLineColor(kYellow);
    g2->SetLineWidth(2);
    g2->Draw("SAME");

    TF1 *g3 = new TF1("g3", "TMath::Gaus(x, 0, sqrt(3.9), true)", -5, 5);
    g3->SetLineColor(kYellow);
    g3->SetLineWidth(2);
    g3->Draw("SAME");

    TF1 *g4 = new TF1("g4", "TMath::Gaus(x, -3, 1, true)", -5, 5);
    g4->SetLineColor(kBlue);
    g4->SetLineWidth(2);
    g4->Draw("SAME");

    // Створюємо легенду 
    TLegend *leg = new TLegend(0.65, 0.65, 0.85, 0.85);
    leg->AddEntry(g1, "#mu = 1, #sigma^{2} = 0.3", "l");
    leg->AddEntry(g2, "#mu = -1, #sigma^{2} = 0.9", "l");
    leg->AddEntry(g3, "#mu = 0, #sigma^{2} = 3.9", "l");
    leg->AddEntry(g4, "#mu = -3, #sigma^{2} = 1", "l");
    leg->SetBorderSize(0); // Прибираємо рамку навколо легенди
    leg->Draw();

    c1->SaveAs("gaussian_magic.png");
}
