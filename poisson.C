void poisson() {
    // Створюємо полотно для малювання
    TCanvas *c1 = new TCanvas("c1", "Poisson Distribution", 800, 600);

    // Створюємо першу лінію (Лямбда = 3, Жовта)
    // Використовуємо вбудовану математику ROOT: TMath::Poisson
    TF1 *p1 = new TF1("p1", "TMath::Poisson(x, [0])", 0, 20);
    p1->SetParameter(0, 3.0);     // Встановлюємо лямбду = 3
    p1->SetLineColor(kYellow);    // Колір
    p1->SetLineWidth(2);          // Товщина лінії
    // Підписуємо осі X та Y
    p1->SetTitle("Poisson Distribution; k (Number of events); Probability P(x=k)");

    // Створюємо другу лінію 
    TF1 *p2 = new TF1("p2", "TMath::Poisson(x, [0])", 0, 20);
    p2->SetParameter(0, 5.0);
    p2->SetLineColor(kRed); 
    p2->SetLineWidth(2);

    // Створюємо третю лінію
    TF1 *p3 = new TF1("p3", "TMath::Poisson(x, [0])", 0, 20);
    p3->SetParameter(0, 7.0);
    p3->SetLineColor(kBlue); 
    p3->SetLineWidth(2);

    // Малюємо все на одному екрані
    p1->Draw();        // Першу малюємо як зазвичай
    p2->Draw("SAME");  // Магічне слово "SAME" малює лінію поверх першої
    p3->Draw("SAME");  // І третю також поверх усіх

    // Легенда
    TLegend *leg = new TLegend(0.7, 0.6, 0.85, 0.85);
    leg->AddEntry(p1, "#lambda = 3", "l");  // ROOT розуміє хештег як грецьку літеру
    leg->AddEntry(p2, "#lambda = 5", "l");
    leg->AddEntry(p3, "#lambda = 7", "l");
    leg->Draw(); // Малюємо табличку

    c1->SaveAs("poisson_magic.png");
}
