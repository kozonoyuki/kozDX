/**
* @file   Pipeline.h
* @brief  レンダーパイプライン
* @author kozonoyuki
* @date   12/25に書き始め
*/

#pragma once
/*
構想：
たとえばシャドウマップを作成したいときには、シャドウマップ作成、シャドウマップ参照しレンダリングの
２回レンダリングが必要であるため、このクラスのインスタンスを２つ作成して動作させる
必要な機能：
レンダーターゲットを決定する
オブジェクトを格納する
デプスステンシルビューを決定する
ブレンドステートを決定する
ビューポートを設定する -> 上の領域？　-> 個別に設定を行うためこの領域？
オブジェクトを描画する
privateテスト
*/

namespace koz
{
	/**
	* @brief パイプラインクラス
	*/
	class Pipeline
	{
	private:
		/**
		* オブジェクトデータ
		*/
		std::vector<std::shared_ptr<Object>> m_ObjectSoup;
	public:
		/**
		* デフォルトコンストラクタ
		*/
		Pipeline();

		/**
		* デストラクタ
		*/
		~Pipeline();
	};
}