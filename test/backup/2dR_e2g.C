{
//=========Macro generated from canvas: c1/c1
//=========  (Sun May 25 21:24:29 2014) by ROOT version5.34/18
   TCanvas *c1 = new TCanvas("c1", "c1",11,55,700,500);
   c1->Range(-0.625,-0.8023081,5.625,7.220772);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->SetBinContent(5,5.807982);
   h_dr->SetBinContent(6,3.280004);
   h_dr->SetBinContent(7,2.032001);
   h_dr->SetBinContent(8,1.44);
   h_dr->SetBinContent(9,0.8959994);
   h_dr->SetBinContent(10,0.8959994);
   h_dr->SetBinContent(11,0.7519996);
   h_dr->SetBinContent(12,0.5759999);
   h_dr->SetBinContent(13,0.6879997);
   h_dr->SetBinContent(14,0.48);
   h_dr->SetBinContent(15,0.6399998);
   h_dr->SetBinContent(16,1.424);
   h_dr->SetBinContent(17,0.352);
   h_dr->SetBinContent(18,0.08000001);
   h_dr->SetBinContent(19,0.048);
   h_dr->SetBinError(5,0.3048409);
   h_dr->SetBinError(6,0.2290851);
   h_dr->SetBinError(7,0.1803108);
   h_dr->SetBinError(8,0.1517893);
   h_dr->SetBinError(9,0.119733);
   h_dr->SetBinError(10,0.119733);
   h_dr->SetBinError(11,0.1096905);
   h_dr->SetBinError(12,0.096);
   h_dr->SetBinError(13,0.104919);
   h_dr->SetBinError(14,0.08763561);
   h_dr->SetBinError(15,0.1011929);
   h_dr->SetBinError(16,0.1509437);
   h_dr->SetBinError(17,0.07504665);
   h_dr->SetBinError(18,0.03577709);
   h_dr->SetBinError(19,0.02771281);
   h_dr->SetEntries(1212);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_dr");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1212   ");
   text = ptstats->AddText("Mean  =  1.575");
   text = ptstats->AddText("RMS   =  0.769");
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
