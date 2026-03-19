#include <TCanvas.h>
#include <TH1D.h>
#include <TRandom3.h>
#include <TApplication.h>
#include <TStyle.h>

// Функція
void DrawGaussianHistogram()
{
    // Показуємо всі дані графіка
    gStyle->SetOptFit(1111);

    TRandom3 rng(0); //генератор чисел. 0 означає, що при кодному запуску "зерно для чисел баратиметься з системного часу

    //Гістограма
    TH1D* h = new TH1D("h","Gaussian Distribution; x; Entries",100,-5,5);

    // Генеруємо 10000 значень для Гаусса
    for(int i = 0; i < 10000; i++)
    {
        double x = rng.Gaus(0,1);
        h->Fill(x);
    }

    // щось типу оформлення
    TCanvas* c = new TCanvas("c","Gaussian Histogram",800,600);

    // апроксимуємо нашу штуку до Гаусса
    h->Fit("gaus");

    // малюємо
    h->Draw();
    c->SaveAs("g_fit.png");
    c->Update();
}

int main(int argc, char** argv)//точка старту
{
    TApplication app("app",&argc,argv);// створює середовище, щоб програмка сама змогла запуститися

    DrawGaussianHistogram();//малюємо

    app.Run();//режим очікування, без якого все моментально б закрилося

    return 0;
}
