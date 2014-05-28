{
//=========Macro generated from canvas: c1/c1
//=========  (Tue May 27 13:16:37 2014) by ROOT version5.34/18
   TCanvas *c1 = new TCanvas("c1", "c1",11,55,700,500);
   c1->Range(-0.625,-0.7915317,5.625,7.123785);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->SetBinContent(5,5.727983);
   h_dr->SetBinContent(6,3.264004);
   h_dr->SetBinContent(7,2.000001);
   h_dr->SetBinContent(8,1.424);
   h_dr->SetBinContent(9,0.9119993);
   h_dr->SetBinContent(10,0.8799994);
   h_dr->SetBinContent(11,0.7519996);
   h_dr->SetBinContent(12,0.5759999);
   h_dr->SetBinContent(13,0.6719998);
   h_dr->SetBinContent(14,0.48);
   h_dr->SetBinContent(15,0.6079999);
   h_dr->SetBinContent(16,1.408);
   h_dr->SetBinContent(17,0.352);
   h_dr->SetBinContent(18,0.08000001);
   h_dr->SetBinContent(19,0.032);
   h_dr->SetBinError(5,0.3027342);
   h_dr->SetBinError(6,0.2285257);
   h_dr->SetBinError(7,0.1788854);
   h_dr->SetBinError(8,0.1509437);
   h_dr->SetBinError(9,0.1207974);
   h_dr->SetBinError(10,0.1186592);
   h_dr->SetBinError(11,0.1096905);
   h_dr->SetBinError(12,0.096);
   h_dr->SetBinError(13,0.1036919);
   h_dr->SetBinError(14,0.08763561);
   h_dr->SetBinError(15,0.09863062);
   h_dr->SetBinError(16,0.1500933);
   h_dr->SetBinError(17,0.07504665);
   h_dr->SetBinError(18,0.03577709);
   h_dr->SetBinError(19,0.02262742);
   h_dr->SetEntries(1198);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_dr");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1198   ");
   text = ptstats->AddText("Mean  =  1.572");
   text = ptstats->AddText("RMS   = 0.7656");
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
