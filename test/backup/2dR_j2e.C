{
//=========Macro generated from canvas: c1/c1
//=========  (Sun May 25 21:28:57 2014) by ROOT version5.34/18
   TCanvas *c1 = new TCanvas("c1", "c1",228,242,700,500);
   c1->Range(-0.625,-0.7554487,5.625,6.799038);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->SetBinContent(5,1.427628);
   h_dr->SetBinContent(6,1.212665);
   h_dr->SetBinContent(7,1.345768);
   h_dr->SetBinContent(8,2.160178);
   h_dr->SetBinContent(9,1.885613);
   h_dr->SetBinContent(10,1.721934);
   h_dr->SetBinContent(11,1.80394);
   h_dr->SetBinContent(12,2.101797);
   h_dr->SetBinContent(13,2.639885);
   h_dr->SetBinContent(14,3.396051);
   h_dr->SetBinContent(15,3.151354);
   h_dr->SetBinContent(16,5.375673);
   h_dr->SetBinContent(17,2.175945);
   h_dr->SetBinContent(18,1.237864);
   h_dr->SetBinContent(19,0.8071713);
   h_dr->SetBinContent(20,0.2682095);
   h_dr->SetBinContent(21,0.02713378);
   h_dr->SetBinError(5,0.1961056);
   h_dr->SetBinError(6,0.1807794);
   h_dr->SetBinError(7,0.190327);
   h_dr->SetBinError(8,0.2415298);
   h_dr->SetBinError(9,0.2253831);
   h_dr->SetBinError(10,0.2152482);
   h_dr->SetBinError(11,0.2203929);
   h_dr->SetBinError(12,0.2379918);
   h_dr->SetBinError(13,0.2666807);
   h_dr->SetBinError(14,0.3025585);
   h_dr->SetBinError(15,0.2913558);
   h_dr->SetBinError(16,0.3801263);
   h_dr->SetBinError(17,0.2417756);
   h_dr->SetBinError(18,0.1825195);
   h_dr->SetBinError(19,0.1473733);
   h_dr->SetBinError(20,0.08481543);
   h_dr->SetBinError(21,0.02713378);
   h_dr->SetEntries(1216);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_dr");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1216   ");
   text = ptstats->AddText("Mean  =  2.439");
   text = ptstats->AddText("RMS   = 0.7644");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_dr->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_dr);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   h_dr->SetLineColor(ci);
   h_dr->GetXaxis()->SetLabelFont(42);
   h_dr->GetXaxis()->SetLabelSize(0.035);
   h_dr->GetXaxis()->SetTitleSize(0.035);
   h_dr->GetXaxis()->SetTitleFont(42);
   h_dr->GetYaxis()->SetLabelFont(42);
   h_dr->GetYaxis()->SetLabelSize(0.035);
   h_dr->GetYaxis()->SetTitleSize(0.035);
   h_dr->GetYaxis()->SetTitleFont(42);
   h_dr->GetZaxis()->SetLabelFont(42);
   h_dr->GetZaxis()->SetLabelSize(0.035);
   h_dr->GetZaxis()->SetTitleSize(0.035);
   h_dr->GetZaxis()->SetTitleFont(42);
   h_dr->Draw("");
   
   TPaveText *pt = new TPaveText(0.4375575,0.94,0.5624425,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("deltaR");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
