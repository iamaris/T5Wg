{
//=========Macro generated from canvas: c1/c1
//=========  (Tue May 27 13:23:05 2014) by ROOT version5.34/18
   TCanvas *c1 = new TCanvas("c1", "c1",11,55,700,500);
   c1->Range(-0.625,-132.6004,5.625,1193.404);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->SetBinContent(5,230);
   h_dr->SetBinContent(6,206);
   h_dr->SetBinContent(7,195);
   h_dr->SetBinContent(8,218);
   h_dr->SetBinContent(9,247);
   h_dr->SetBinContent(10,296);
   h_dr->SetBinContent(11,299);
   h_dr->SetBinContent(12,341);
   h_dr->SetBinContent(13,410);
   h_dr->SetBinContent(14,505);
   h_dr->SetBinContent(15,703);
   h_dr->SetBinContent(16,979);
   h_dr->SetBinContent(17,447);
   h_dr->SetBinContent(18,210);
   h_dr->SetBinContent(19,145);
   h_dr->SetBinContent(20,49);
   h_dr->SetBinContent(21,11);
   h_dr->SetBinError(5,15.16575);
   h_dr->SetBinError(6,14.3527);
   h_dr->SetBinError(7,13.96424);
   h_dr->SetBinError(8,14.76482);
   h_dr->SetBinError(9,15.71623);
   h_dr->SetBinError(10,17.20465);
   h_dr->SetBinError(11,17.29162);
   h_dr->SetBinError(12,18.46619);
   h_dr->SetBinError(13,20.24846);
   h_dr->SetBinError(14,22.47221);
   h_dr->SetBinError(15,26.51415);
   h_dr->SetBinError(16,31.28898);
   h_dr->SetBinError(17,21.14237);
   h_dr->SetBinError(18,14.49138);
   h_dr->SetBinError(19,12.04159);
   h_dr->SetBinError(20,7);
   h_dr->SetBinError(21,3.316625);
   h_dr->SetEntries(5491);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_dr");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 5491   ");
   text = ptstats->AddText("Mean  =  2.522");
   text = ptstats->AddText("RMS   = 0.7538");
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
