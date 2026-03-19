void gaus_homework() {
    gStyle->SetOptFit(1111);

    TRandom3 rng(0);
    TH1D* h = new TH1D("h", "Gaussian Distribution; x; Entries", 100, -5, 5);

    int nEvents = 10000;
    double binWidth = h->GetBinWidth(1); 

    for(int i = 0; i < nEvents; i++) {
        h->Fill(rng.Gaus(0, 1));
    }

    TCanvas* c = new TCanvas("c", "Combo Fit", 800, 600);

    // Спосіб 1 (дістаємо параметри)
    h->Fit("gaus", "Q"); 
    TF1 *fitGaus = h->GetFunction("gaus");
    
    double p0_const = fitGaus->GetParameter(0); // висота
    double p2_sigma = fitGaus->GetParameter(2); // ширина

    // Спосіб 2 (gaussian_pdf)
    TF1 *pdf = new TF1("gaussian_pdf", "[0] / ([2] * sqrt(2*TMath::Pi())) * exp(-0.5 * pow((x-[1])/[2], 2))", -5, 5);
    
    // Даємо стартові підказки
    pdf->SetParameter(0, nEvents * binWidth); // Підказуємо очікувану площу
    pdf->SetParameter(1, 0);                  // Підказуємо центр
    pdf->SetParameter(2, 1);                  // Підказуємо ширину

    // Робимо фіт нашою новою функцією (вона замінить стару на малюнку)
    // Літера "L" - це метод максимальної правдоподібності (краще працює)
    h->Fit("gaussian_pdf", "L");

    TF1 *fitPdf = h->GetFunction("gaussian_pdf");
    double areaPdf = fitPdf->GetParameter(0);
    double eventsPdf = areaPdf / binWidth;

    cout << "  Згенеровано подій: " << nEvents << endl;
    cout << "  Ширина одного стовпчика: " << binWidth << endl;
    cout << "  Constant (P0) : " << p0_const << endl;
    cout << "  Sigma    (P2) : " << p2_sigma << endl;
    cout << "  Готовий результат від gaussian_pdf:" << endl;
    cout << "  Площа : " << areaPdf << endl;
    cout << "  Кількість подій   : " << eventsPdf << endl;

    h->Draw();
    c->SaveAs("homework_gaus.png");
}
