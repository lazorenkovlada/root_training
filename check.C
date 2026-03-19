void check() {
    // Відкриваємо твій створений файл
    TFile *file = new TFile("vlada_ABCDE.root", "READ");

    // Дістаємо графік за його внутрішнім паспортом
    TH1F *h1 = (TH1F*)file->Get("vlada_hist"); 

    // Створюємо полотно і малюємо
    TCanvas *c1 = new TCanvas("c1", "Check", 800, 600);
    h1->Draw();
    c1->SaveAs("secret_graph.png");
}
