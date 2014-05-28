{
//=========Macro generated from canvas: c1/c1
//=========  (Tue May 27 19:05:05 2014) by ROOT version5.34/18
   TCanvas *c1 = new TCanvas("c1", "c1",11,55,700,500);
   c1->Range(-0.625,-1.162922,5.625,10.4663);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h_dr = new TH1F("h_dr","deltaR",25,0,5);
   h_dr->SetBinContent(5,6.805206);
   h_dr->SetBinContent(6,7.441206);
   h_dr->SetBinContent(7,8.140806);
   h_dr->SetBinContent(8,5.406004);
   h_dr->SetBinContent(9,4.833604);
   h_dr->SetBinContent(10,4.388403);
   h_dr->SetBinContent(11,5.215204);
   h_dr->SetBinContent(12,3.561603);
   h_dr->SetBinContent(13,3.625203);
   h_dr->SetBinContent(14,4.770004);
   h_dr->SetBinContent(15,4.134003);
   h_dr->SetBinContent(16,3.943203);
   h_dr->SetBinContent(17,1.272);
   h_dr->SetBinContent(18,0.318);
   h_dr->SetBinContent(19,0.0636);
   h_dr->SetBinContent(20,0.1272);
   h_dr->SetBinError(5,0.6578835);
   h_dr->SetBinError(6,0.6879392);
   h_dr->SetBinError(7,0.7195519);
   h_dr->SetBinError(8,0.586363);
   h_dr->SetBinError(9,0.5544519);
   h_dr->SetBinError(10,0.5283013);
   h_dr->SetBinError(11,0.5759225);
   h_dr->SetBinError(12,0.4759388);
   h_dr->SetBinError(13,0.4801695);
   h_dr->SetBinError(14,0.5507922);
   h_dr->SetBinError(15,0.5127596);
   h_dr->SetBinError(16,0.5007869);
   h_dr->SetBinError(17,0.2844278);
   h_dr->SetBinError(18,0.1422139);
   h_dr->SetBinError(19,0.0636);
   h_dr->SetBinError(20,0.08994398);
   h_dr->SetEntries(1007);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_dr");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1007   ");
   text = ptstats->AddText("Mean  =  1.887");
   text = ptstats->AddText("RMS   = 0.7342");
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
