{
//=========Macro generated from canvas: c1/c1
//=========  (Tue May 27 19:02:48 2014) by ROOT version5.34/18
   TCanvas *c1 = new TCanvas("c1", "c1",11,55,700,500);
   c1->Range(-0.625,-1.735737,5.625,15.62163);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->SetBinContent(5,10.11961);
   h_dr->SetBinContent(6,10.90803);
   h_dr->SetBinContent(7,10.53002);
   h_dr->SetBinContent(8,9.676793);
   h_dr->SetBinContent(9,9.406784);
   h_dr->SetBinContent(10,9.665993);
   h_dr->SetBinContent(11,9.341982);
   h_dr->SetBinContent(12,8.823565);
   h_dr->SetBinContent(13,9.622791);
   h_dr->SetBinContent(14,10.58402);
   h_dr->SetBinContent(15,11.75046);
   h_dr->SetBinContent(16,12.8521);
   h_dr->SetBinContent(17,6.447553);
   h_dr->SetBinContent(18,3.056389);
   h_dr->SetBinContent(19,1.3716);
   h_dr->SetBinContent(20,0.5292001);
   h_dr->SetBinContent(21,0.1296);
   h_dr->SetBinError(5,0.3305929);
   h_dr->SetBinError(6,0.3432294);
   h_dr->SetBinError(7,0.3372299);
   h_dr->SetBinError(8,0.3232792);
   h_dr->SetBinError(9,0.3187373);
   h_dr->SetBinError(10,0.3230987);
   h_dr->SetBinError(11,0.3176375);
   h_dr->SetBinError(12,0.3086987);
   h_dr->SetBinError(13,0.3223759);
   h_dr->SetBinError(14,0.3380935);
   h_dr->SetBinError(15,0.3562363);
   h_dr->SetBinError(16,0.3725609);
   h_dr->SetBinError(17,0.2638827);
   h_dr->SetBinError(18,0.1816841);
   h_dr->SetBinError(19,0.1217098);
   h_dr->SetBinError(20,0.0756);
   h_dr->SetBinError(21,0.0374123);
   h_dr->SetEntries(12483);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_dr");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 12483  ");
   text = ptstats->AddText("Mean  =  2.147");
   text = ptstats->AddText("RMS   = 0.7906");
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
